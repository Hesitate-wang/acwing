//
// Created by Wang Jianan on 24-10-16.
//

#include <iostream>
#include <vector>

struct Dsu {
    std::vector<int> vec;
    explicit Dsu(int size):vec(size) {
        //初始化集合
        for(int i = 0; i <size; ++i) {
            vec[i] = i;
        }
    }
    void merge(int a, int b);
    int find(int a, int b);
    [[nodiscard]] inline int search(int x){
        return x==vec[x]?x: vec[x] = search(vec[x]);
    }  //路径压缩
};

void Dsu::merge(int a, int b) {
    int x = search(a);
    int y = search(b);
    if(x!=y) {
        vec[x] = y;
    }
}
int Dsu::find(int a, int b){
    int x = search(a);
    int y = search(b);
    if(x != y) {
        return 0;
    }else {
        return x;
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    Dsu dsu(n+1);
    while(m--) {
        char op;
        int a, b;
        std::cin >> op >> a >> b;
        if(op == 'M') {
            dsu.merge(a, b);
        }else {
            if(int res = dsu.find(a, b)) {
                std::cout << "Yes" << std::endl;
            }else {
                std::cout << "No" << std::endl;
            }
        }
    }
}