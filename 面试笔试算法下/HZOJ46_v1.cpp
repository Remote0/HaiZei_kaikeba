/*************************************************************************
	> File Name: HZOJ46_v1.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 09:31:19 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 500000

vector<int> mark[MAX_N + 5];
int dp[MAX_N + 5];

int expand(string &s, int i, int j) {
    while (s[i] == s[j]) {
        mark[j + 1].push_back(i + 1);
        --i, ++j;
        if (i < 0 || j >= s.size()) break;
    }
    return 1;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        expand(s, i, i);
        i + 1 < s.size() && expand(s, i, i + 1);
    }
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = i;
        for (int j = 0; j < mark[i].size(); j++) {
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1);
        }
    }
    cout << dp[s.size()] - 1 << endl;
    return 0;
}
