//
// Created by Wang Jianan on 24-10-8.
//KMP
/*
模式串 aba; 目标串ababa
拼接 aba#ababa
 */

#include <iostream>
#include <vector>
void next(std::vector<int> prefix, const std::string &s, const int start, const int n) {
    prefix[0] = 0;
    for(int i = 1; i < s.size(); ++i) {
        int j = prefix[i - 1];
        while(j>0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if(s[i] == s[j]) {
            ++j;
        }
        prefix[i] = j;
        if(j == n) {
            std::cout << i - start - n + 1 << ' ';
        }
    }
}
int main() {
    int N, M;
    std::string s, p;
    std::cin >> N >> p >> M >> s;
    std::vector<int> prefix(N + M + 1);
    std::string str = p + "#" + s;
    next(prefix, str, N + 1, N);
}
