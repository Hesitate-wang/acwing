//
// Created by Wang Jianan on 24-10-18.
//食物链
#include <iostream>
#include <vector>

std::vector<int> vec(50001);  //A B C 集合
std::vector<int> dis(50001);   //到祖宗节点的距离  %3 == 0: 同类, %3 == 1

int search(int x) {
    if(vec[x] != x) {
        int nex = vec[x];
        vec[x] = search(nex);
        dis[x] = (dis[x] + dis[nex]) % 3;
    }
    return vec[x];
}

int main() {
    int N, K, ans = 0;
    std::cin >> N >> K;
    for(int i = 0;i < 50001; ++i) {
        vec[i] = i;
        dis[i] = 0;
    }
    while(K--) {
        int op, a, b;
        std::cin >> op >> a >> b;
        if( a > N || b > N) {
            ++ans;
            continue;
        }
        int x = search(a);
        int y = search(b);
        if(op == 1) {
            // a == b
            if(x == y && (dis[a] - dis[b] + 3) % 3 != 0) {
                ++ans;
            }else{
                vec[x] = y;
                dis[x] = dis[b] - dis[a];
            }
        }else {
            // a -> b
            if(a == b) {
                ++ans;
                continue;
            }
            if(x == y && (dis[a] - dis[b] + 3) % 3 != 1) {
                ++ans;
            }else{
                vec[x] = y;
                dis[x] = dis[b] - dis[a] + 1;
            }
        }
    }
    std::cout << ans <<std::endl;
}
