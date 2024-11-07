//
// Created by Admin on 2024/9/19.
//
#include<iostream>
const int N = 100001;
int main(){
    int n, m;
    int seq[N];
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i)
        std::cin >> seq[i];

    int diff[N];
    diff[0] = seq[0];
    for(int i = 1; i < n; ++i){
        diff[i] = seq[i] - seq[i-1];
    }

    while(m--){
        int l, r, c;
        std::cin >> l >> r >> c;
        diff[l-1] += c;
        diff[r] -= c;
    }
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += diff[i];
        std::cout << sum << " ";
    }
}