//
// Created by Wang Jianan on 24-10-31.
//

#include <iostream>
#include <vector>
#include <limits>

int G[510][510];
int distance[510] = {std::numeric_limits<int>::max()};
bool vis[510] = {false};
bool check(const int n) {
    for(int i = 1; i < n + 1;++i) {
        if(!vis[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    for(auto & i : G) {
        std::fill_n(i, 510, std::numeric_limits<int>::max());
    }
    std::fill_n(distance, 510, std::numeric_limits<int>::max());
    while(m --) {
        int x, y, e;
        std::cin >> x >> y >> e;
        G[x][y] = std::min(e, G[x][y]);
    }
    distance[1] = 0;
    vis[1] = true;
    int idx = 1, min = std::numeric_limits<int>::max();
    while(!check(n)) {
        //更新临近节点 选出更新后的距离最短节点
        for(int i = 1; i <= n; ++i) {
            //update
            if(G[idx][i] != std::numeric_limits<int>::max() && !vis[i]) {
                distance[i] = std::min(distance[i], distance[idx] + G[idx][i]);
            }
        }
        for(int i = 1; i <= n; ++i) {
            //select next node
            if(!vis[i] && distance[i] <= min) {
                idx = i;
                min = distance[i];
            }
        }
        vis[idx] = true;
        min = std::numeric_limits<int>::max();
    }
    int res = 0;
    if(distance[n] == std::numeric_limits<int>::max()) {
        res = -1;
    }else {
        res = distance[n];
    }
    std::cout << res << std::endl;
}
