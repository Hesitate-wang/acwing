//
// Created by Wang Jianan on 24-9-19.
//
#include<iostream>

const int N = 1010;

void insert(int a[][1010], int x1, int y1, int x2, int y2, int c) {
    //二维数组 形参要指定第二维度
    a[x1][y1] += c;
    a[x1][y1 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}
int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    int matrix[N][N];
    int pre[N][N];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            insert(pre, i, j, i, j, matrix[i][j]);
        }
    }

    while(q--) {
        int x1, y1, x2, y2, c;
        std::cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(pre, x1, y1, x2, y2, c);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
            std::cout << pre[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}