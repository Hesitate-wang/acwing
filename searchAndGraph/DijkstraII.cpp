//
// Created by Wang Jianan on 24-11-5.
//
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
int main() {
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> vis;
    std::vector visited(n + 1, false);
    std::vector distance(n +1, std::numeric_limits<int>::max());
    std::vector G(n + 1, std::vector<std::pair<int, int>>());

    while(m --) {
        int x, y, e;
        std::cin >> x >> y >> e;
        std::pair p{e, y};
        G[x].push_back(p);
    }
    distance[1] = 0;
    int idx = 1;
    vis.emplace(0, 1);
    while(!vis.empty()) {
        //更新临近节点 选出更新后的距离最短节点
        idx = vis.top().second;
        vis.pop();
        if(visited[idx]) {
            continue;
        }
        visited[idx] = true;
        for(auto &p : G[idx]) {
            //update
            if(!visited[p.second] && distance[p.second] > distance[idx] + p.first) {
                distance[p.second] = distance[idx] + p.first;
                vis.emplace(distance[p.second], p.second);
            }
        }
    }
    int res = 0;
    if(distance[n] == std::numeric_limits<int>::max()) {
        res = -1;
    }else {
        res = distance[n];
    }
    std::cout << res << std::endl;
}