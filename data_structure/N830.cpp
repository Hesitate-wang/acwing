//
// Created by Wang Jianan on 24-10-8.
//每个数左边第一个比他小的数字 单调栈

#include <iostream>
#include <stack>

int main() {
    int N;
    std::cin >> N;
    std::stack<int> s;
    int x;
    while(N--) {
        std::cin >> x;
        while(!s.empty()) {
            if(s.top() < x) {
                std::cout << s.top() << ' ';
                s.push(x);
                break;
            }else {
                s.pop();
            }
        }
        if(s.empty()) {
            s.push(x);
            std::cout << -1 << ' ';
        }
    }
}
