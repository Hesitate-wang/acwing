//
// Created by Wang Jianan on 24-9-23.
//
//数组元素的目标和
#include<iostream>
int search(int arr[],int i, int j, int target) {
    if(i > j) return -1;
    int mid = (i + j) >> 1;
    if(arr[mid] == target) {
        return mid;
    }else if(arr[mid] < target) {
        return search(arr, mid + 1, j, target);
    }else {
        return search(arr, i, mid - 1, target);
    }
}
int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    int A[n+1], B[m+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    for(int i = 0; i < n; ++i) {
        int target = x - A[i];
        int index = search(B, 0, m-1, target);
        if(index != -1) {
            printf("%d %d", i, index);
            break;
        }
    }
}