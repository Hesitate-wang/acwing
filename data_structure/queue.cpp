//
// Created by Wang Jianan on 24-10-8.
//
#include <iostream>
#include <deque>
#include <unordered_map>
struct queue {
    std::deque<int> q;
    void push(int);
    void pop();
    bool empty() const;
    int query() const;
};

void queue::push(int x) {
    q.push_back(x);
}

void queue::pop() {
    if(!empty()) {
        q.pop_front();
    }
}

bool queue::empty() const{
    return q.empty();
}

int queue::query() const {
    return q.front();
}

int main() {
    int M;
    std::cin >> M;
    queue q;
    while(M --) {
        std::string op;
        std::cin >> op;
        if(op == "push") {
            int x;
            std::cin >> x;
            q.push(x);
        }else if(op == "pop") {
            q.pop();
        }else if(op == "empty") {
            if(q.empty()) {
                std::cout << "YES" << std::endl;
            }else {
                std::cout << "NO" << std::endl;
            }
        }else {
            std::cout << q.query() << std::endl;
        }
    }
}