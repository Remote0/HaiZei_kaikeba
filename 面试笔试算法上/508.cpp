/*************************************************************************
	> File Name: 508.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 07:39:38 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[1005], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i == 0) {
            ans += num[0];
            break;
        } else if (i == 1) {
            ans += num[1];
            break;
        } else if (i == 2) {
            ans += num[1] + num[0] + num[2];
            break;
        } else {
            ans += min(num[1] + num[0] + num[i] + num[1], num[i] + num[0] + num[i - 1] + num[0]);
        }
    }
    cout << ans << endl;
    return 0;
}
