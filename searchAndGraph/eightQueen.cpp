//
// Created by Wang Jianan on 24-10-23.
// P1219
//相同对角线上的元素坐标有规律可循
#include <iostream>
#include <vector>

int diagonal[26];
int unDiagonal[26];
int cols[13];
std::vector<int> ans;
int res = 0;
int ou = 0;


bool check(int &row, int &col) {
    if(cols[col] || diagonal[row - col + 13] || unDiagonal[row + col]) {
        return false;
    }

    return true;
}
int numOfQueens = 0;

void dfs(int row, int n) {
    if(numOfQueens == 0) {
        ++res;
        if(ou >= 3) return;
        ++ou;
        for(int &i : ans) {
            std::cout << i + 1 << ' ';
        }
        std::cout << '\n';
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(check(row, i)) {
            ans.push_back(i);
            cols[i] = 1;
            diagonal[row - i + 13] = 1;
            unDiagonal[row + i] = 1;
            --numOfQueens;
            dfs(row + 1, n);
            ans.pop_back();
            cols[i] = 0;
            diagonal[row - i + 13] = 0;
            unDiagonal[row + i] = 0;
            ++numOfQueens;
        }
    }
}


int main() {
    int n;
    std::cin >> n;
    numOfQueens = n;
    dfs(0, n);
    std::cout << res << '\n';
}
