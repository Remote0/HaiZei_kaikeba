/*************************************************************************
	> File Name: 240.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 06:46:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char mmap[1000][1000];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};

void func(int x, int y, int n) {
    if (n == 1) {
        mmap[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);//左上
    func(x, y + num[n] / 3 * 2, n - 1);//右上
    func(x + num[n] / 3 * 2, y, n - 1);//左下
    func(x + num[n - 1], y + num[n  -1], n - 1);//中间
    func(x + num[n - 1] * 2, y + num[n - 1] * 2, n - 1);//右下
    return ;
}

int main() {
    func(0, 0, 7);
    int t;
    while (cin >> t) {
        if (t == -1) {
            break;
        }
        for (int i = 0; i < num[t]; i++) {
            for (int j = 0; j < num[t]; j++) {
                if (mmap[i][j] == 0) {
                    cout << " ";
                } else {
                    cout << 'X';
                }
            }
            cout << endl;
        }
        cout << "-" << endl;
    }

    return 0;
}
