//
// Created by Wang Jianan on 24-10-24.
//
#include <iostream>
#include <stack>
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
int main() {
    int n;
    std::cin >> n;
    std::stack<int> st;
    int row = 0, col =0;
    while(row >= 0) {
        if(row == n) {
            ++res;
            if(ou < 3) {
                for(int &i : ans) {
                    std::cout << i + 1 << ' ';
                }
                std::cout << '\n';
                ++ou;
            }
            --row;
            col = st.top() + 1;
            ans.pop_back();
            diagonal[row - st.top() + 13] = 0;
            unDiagonal[row + st.top()] = 0;
            cols[st.top()] = 0;
            st.pop();
        }
        bool found = false;
        while(col < n) {
            if(check(row, col)) {
                found = true;
                ans.push_back(col);
                cols[col] = 1;
                diagonal[row - col + 13] = 1;
                unDiagonal[row + col] = 1;
                st.push(col);
                ++row;
                col = 0;
                break;
            }
            ++col;
        }
        if(!found) {
            if(st.empty()) break;
            --row;
            col = st.top() + 1;
            ans.pop_back();
            diagonal[row - st.top() + 13] = 0;
            unDiagonal[row + st.top()] = 0;
            cols[st.top()] = 0;
            st.pop();
        }
    }
    std::cout << res << '\n';
}