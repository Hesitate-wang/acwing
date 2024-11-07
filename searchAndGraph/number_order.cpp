//
// Created by Wang Jianan on 24-10-24.
// 排列数字

#include <iostream>
#include <vector>

std::vector<int> out;
int visited[10];
int nums = 0;

void dfs(int n) {
    if(nums == 0) {
        for(int &i : out) {
            std::cout << i + 1 << " ";
        }
        std::cout << std::endl;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = 1;
            --nums;
            out.push_back(i);
            dfs(n);
            visited[i] = 0;
            out.pop_back();

            ++nums;
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    nums = n;
    dfs(n);
}
