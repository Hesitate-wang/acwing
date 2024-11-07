//
// Created by Wang Jianan on 24-10-14.
//最大异或对
#include <iostream>


const int SIZE = 5e6;
int nums[100010] = { 0 };  //输入的全部整数
int trie[SIZE][2];  //待建立的字典树
int cnt = 0;

void insert(int n) {
    int p = 0;
    for(int i = 30; i >= 0; --i) {
        const int t = (n >> i) & 1;
        if(!trie[p][t]) {
            trie[p][t] = ++cnt;
        }
        p = trie[p][t];
    }
}

int search(int n) {
    int p = 0, res = 0;
    for(int i = 30; i >= 0; --i) {
        const int t = (n >> i) & 1;
        if(trie[p][t ^ 1]) {  //如果存在不同的 走不同的
            p = trie[p][t ^ 1];
            res += 1 << i;
        }else {
            p = trie[p][t];
        }
    }
    return res;
}
int main() {
    int N;
    std::cin >> N;
    for(auto &node : trie) {
        std::fill_n(node, 2, 0);
    }
    for(int i = 0; i < N; ++i) {
        std::cin >> nums[i];
        insert(nums[i]);
    }
    int ans = -1;
    for(int i = 0; i < N; ++i) {
        ans = std::max(ans, search(nums[i]));
    }
    std::cout << ans;
}
