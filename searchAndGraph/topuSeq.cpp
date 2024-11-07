//
// Created by Wang Jianan on 24-10-25.
//


#include <iostream>
#include <queue>


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> G(n + 1);
    std::vector<int> inDegree(n + 1);
    while(m--) {
        int from, to;
        std::cin >> from >> to;
        G[from].push_back(to);
        inDegree[to]++;
    }
    std::queue<int> q;
    for(int i = 1; i <=n; ++i) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    std::vector<int> out;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        out.push_back(cur);
        for(auto &next : G[cur]) {
            inDegree[next]--;
            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    if(out.size() != n) {
        std::cout << -1;
    }else {
        for(int & it : out) {
            std::cout << it << " ";
        }
    }
}