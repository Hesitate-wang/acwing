//
// Created by Wang Jianan on 24-10-23.
//
//相同对角线上的元素坐标有规律可循
#include <iostream>


int checkerBoard[13][13];
int diagonal[26];
int unDiagonal[26];
int cols[13];


bool check(int &row, int &col) {
    if(cols[col] || diagonal[row - col + 13] || unDiagonal[row + col]) {
        return false;
    }

    return true;
}
int numOfQueens = 0;

void dfs(int row, int n) {
    if(numOfQueens == 0) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(checkerBoard[i][j] == 1) {
                    std::cout << 'Q';
                }else {
                    std::cout << '.';
                }
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(check(row, i)) {
            checkerBoard[row][i] = 1;
            cols[i] = 1;
            diagonal[row - i + 13] = 1;
            unDiagonal[row + i] = 1;
            --numOfQueens;
            dfs(row + 1, n);
            checkerBoard[row][i] = 0;
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
}