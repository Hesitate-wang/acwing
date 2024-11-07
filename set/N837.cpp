//
// Created by Wang Jianan on 24-10-18.
//连通块中点的数量
#include <iostream>
#include <vector>

std::vector<int> vec(100004);
int map[100004];
int search(const int x) {
    //寻找x所在的集合根节点
    return x == vec[x]? x : vec[x] = search(vec[x]);
}

void connect(int a, int b) {
    //将两者所在集合合并
    int x =search(a);
    int y = search(b);
    if(x!=y) {
        vec[y] = x;
        map[x] += map[y];
        map[y] = 0;
    }
}
int numOfDot(const int a) {
    //返回所在集合的点的个数
    return map[search(a)];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::fill_n(map, 100004, 1);
    for(int i = 0; i < 100004; ++i) {
        vec[i] = i;
    }
    while(m --) {
        std::string s;
        int a, b;
        std::cin >> s;
        if(s == "C") {
            std::cin >> a >> b;
            connect(a, b);
        }else if(s == "Q1") {
            std::cin >> a >> b;
            if(search(a) != search(b)) {
                std::cout << "No" << std::endl;
            }else {
                std::cout << "Yes" << std::endl;
            }
        }else {
            std::cin >> a;
            std::cout << map[search(a)] << std::endl;
        }
    }
}