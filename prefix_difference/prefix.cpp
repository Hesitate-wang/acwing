//
// Created by Admin on 2024/9/9.
//
#include<iostream>

int main(){
    int n = 0;  //长度为n的整数序列
    int m = 0;  //m个询问 每个询问包括一堆l, r. 返回原序列中序号为l 到 r的整数和
    std::cin >> n >> m;
    int l = 0, r = 0;
    int prefix[n + 1];
    prefix[0] = 0;
    //依次修改前缀和
    for(int i = 1; i < n + 1; ++i){
        int temp = 0;
        std::cin >> temp;
        prefix[i] = prefix[i - 1] + temp;
    }

    for(int i = 0; i < m; ++i){
        std::cin >> l >> r;
        std::cout << (prefix[r] - prefix[l - 1]) << std::endl;
    }
}