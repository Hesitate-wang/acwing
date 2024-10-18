//
// Created by Wang Jianan on 24-10-12.
//Trie字符串统计 字典树 支持插入和查询操作
#include <iostream>
#include <vector>
struct Trie {
    std::vector<std::vector<int>> trie;
    int cnt;
    std::vector<int> flag;
    Trie():trie(100010, std::vector<int>(26)), cnt(0), flag(100010){};
    void insert(std::string &str);
    int query(std::string &str) const;
};

void Trie::insert(std::string &str) {
    int p = 0;
    for(char &c : str) {
        if(!trie[p][c - 'a']) {
            trie[p][c - 'a'] = ++cnt;  //开新节点存储
        }
        p = trie[p][c - 'a'];
    }
    ++flag[p];
}

int Trie::query(std::string &str) const {
    int p = 0;
    for(char &c : str) {
        if(trie[p][c - 'a']) {
            p = trie[p][c - 'a'];
        }else {
            return 0;
        }
    }
    return flag[p];
}

int main() {
    int N = 0;
    std::cin >> N;
    Trie tree;
    while(N --) {
        char c;
        std::string s;
        std::cin >> c >> s;
        if(c == 'I') {
            tree.insert(s);
        }else {
            std::cout << tree.query(s) << std::endl;;
        }
    }
}

