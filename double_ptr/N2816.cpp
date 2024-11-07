//
// Created by Wang Jianan on 24-9-23.
//
//判断子序列
#include <iostream>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int A[n + 1], B[m + 1];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &B[i]);
    }
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(A[i] == B[j]) {
            ++i;
        }
        ++j;
    }
    if(i < n) {
        printf("No");
    }else {
        printf("Yes");
    }
}