//
// Created by Wang Jianan on 24-10-1.
//
#include <iostream>
#include <unordered_map>
#include <algorithm>
const int SZ = 1e5 + 2;

class Stack {
public:
    Stack(): nums(0) {
        std::fill(vec, vec + SZ, 0);
    }
    void push(int);
    int pop();
    bool isEmpty() const;
    int query() const;

private:
    int vec[SZ];
    int nums;
};

void Stack::push(int val) {
    vec[nums++] = val;
}

int Stack::pop() {
     return vec[--nums];
}

bool Stack::isEmpty() const {
    return nums == 0;
}

int Stack::query() const {
    return vec[nums - 1];
}



int main() {
    int M;
    std::cin >> M;
    Stack s;
    std::unordered_map<std::string, int> map{
    {"push", 1},
    {"pop", 2},
    {"empty", 3},
    {"query", 4}
    };
    while(M --) {
        std::string in;
        std::cin >> in;
        switch(map[in]) {
            case 1: {
                int x;
                std::cin >> x;
                s.push(x);
                break;
            }
            case 2: {
                s.pop();
                break;
            }
            case 3: {
                std::cout << (s.isEmpty()?"YES":"NO") << std::endl;
                break;
            }
            case 4: {
                std::cout << s.query() << std::endl;
                break;
            }
            default:
                std::cout << "wrong input" << std::endl;
        }
    }
}