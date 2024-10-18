//
// Created by Wang Jianan on 24-10-5.
//表达式求值  同优先级运算符 确保从左到右的顺序 先计算再入栈
#include <iostream>
#include <unordered_map>

#include <stack>
int check = 0;
int calculate(int x1, int x2, char op) {
    switch (op) {
        case '+':
            return x1 + x2;
        case '-':
            return x1 - x2;
        case '*':
            return x1 * x2;
        case '/': {
            return x1 / x2;
        }

        default: {
            std::cerr << "Invalid operation" << std::endl;
            return -1;
        }
    }
}

int main() {
    std::unordered_map<char, int> signPriority{
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2}
    };
    std::stack<char> operatorStack;
    std::stack<int> numStack;
    std::string str;
    std::cin >> str;
    std::string x("");
    for(std::string::size_type i = 0; i < str.size(); ++i) {
        check = i;
        if(isdigit(str[i])) { // 处理数字
            x.push_back(str[i]);
            continue;
        }
        if(!x.empty()) {
            numStack.push(std::stoi(x));
            x = "";
        }
        if(str[i] == '(') {
            operatorStack.push(str[i]);
        }else if(str[i] == ')') {
            while(operatorStack.top() != '(') {
                char op = operatorStack.top();
                operatorStack.pop();
                int x1 = numStack.top();
                numStack.pop();
                int x2 = numStack.top();
                numStack.pop();
                int ans = calculate(x2, x1, op);
                numStack.push(ans);
            }
            operatorStack.pop();
        }else {
            while(!operatorStack.empty() && signPriority[str[i]] <= signPriority[operatorStack.top()]) {
                //即使运算符优先级相等 也应该先计算栈内运算符再入栈
                char op = operatorStack.top();
                operatorStack.pop();
                int x1 = numStack.top();
                numStack.pop();
                int x2 = numStack.top();
                numStack.pop();
                int ans = calculate(x2, x1, op);
                numStack.push(ans);
            }
            operatorStack.push(str[i]);
        }
    }
    //最后一个数字
    if(!x.empty()) {
        numStack.push(std::stoi(x));
    }
    //处理最后的运算符
    while(!operatorStack.empty()) {
        char op = operatorStack.top();
        operatorStack.pop();
        int x1 = numStack.top();
        numStack.pop();
        int x2 = numStack.top();
        numStack.pop();
        int ans = calculate(x2, x1, op);
        numStack.push(ans);
    }
    std::cout << numStack.top() << std::endl;
}