//
// Created by Wang Jianan on 24-10-25.
//
// 寻找树的重心
//深度优先搜索 任一节点 其子树的节点数可以用dfs求得
#include <iostream>
#include <vector>
#include <climits>

void dfs(int i, std::vector<std::vector<int>> &tree, std::vector<int> &visit, std::vector<std::vector<int>> &dist, std::vector<int> &parent) {
    visit[i] = 1;
    int subTrees = 0;
    for(auto &next: tree[i]) {
        if(!visit[next]) {
            dfs(next, tree, visit, dist, parent);
            dist[i].push_back(dist[next].back() + 1);
            subTrees += dist[i].back();
        }
    }
    dist[i].push_back(subTrees);
    parent[i] = parent.size() - subTrees - 2;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> tree(n+1);
    std::vector<std::vector<int>> dist(n+1);  // to distance
    std::vector<int> upNodes(n+1);
    std::vector<int> visited(n+1);
    --n;
    while(n--) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, tree, visited, dist, upNodes);
    int max = INT_MAX;
    for(int i = 1; i < visited.size(); ++i) {
        int max_ = 0;
        for(int j = 0; j < dist[i].size() - 1; ++ j) {
            max_ = std::max(max_, dist[i][j]);
        }
        max_ = std::max(max_, upNodes[i]);
        max = std::min(max, max_);
    }
    std::cout << max << '\n';
}