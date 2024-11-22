//Bellman-Flord 算法
//求单源最短路径 且包括负边

#include <iostream>
#include <vector>
#include <limits>
const int SIZE = 510;
const int INF = std::numeric_limits<int>::max();
int G[SIZE];
struct edge{
    int from, to, dis;
    edge(int x, int y, int z):from(x), to(y), dis(z){}
};

std::vector<edge> edges;

int main(){
    int n, m, k;
    std::cin >> n >> m >> k;
    while(m --){
        int x, y, dis;
        std::cin >> x >> y >> dis;
        edges.emplace_back(x, y, dis);
    }
    std::fill_n(G, SIZE, INF);
    G[1] = 0;
    for(int i = 1; i < k + 1; ++i){
        int backup[SIZE];
        std::copy(G, G + SIZE, backup);
        for(auto &nex : edges){
            //backup[nex.from] + nex.dis < G[nex.to]
            if(backup[nex.from]!=INF && G[nex.to] > nex.dis + backup[nex.from]){
                //负权边的存在导致不能减法 不然INF-minus会溢出
                G[nex.to] = backup[nex.from] + nex.dis;
            }
        }
    }
    if(G[n] == INF){
        std::cout << "impossible";
    }else{
        std::cout << G[n];
    }
}