//
// Created by Wang Jianan on 24-10-24.
//
#include <iostream>
#include <climits>
#include <deque>
int dp[110][110];
int G[110][110];
std::deque<std::pair<int, int>> ue;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            std::cin >> G[i][j];
        }
    }
    dp[1][1] = 0;
    ue.emplace_back(1, 1);
    G[1][1] = 1;
    //外围用墙围堵 适当增加内存降低边界检查繁琐程度
    for(int i = 0; i <= m + 1; ++i) {
        G[0][i] = 1;
        G[n+1][i] = 1;
    }
    for(int i = 0; i <= n + 1; ++i) {
        G[i][0] = 1;
        G[i][m+1] = 1;
    }
    while(!ue.empty()) {
        int i = ue.front().first;
        int j = ue.front().second;
        ue.pop_front();
        if(i == n && j == m) {
            break;
        }
        for(int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!G[ni][nj]) {
                ue.emplace_back(ni, nj);
                dp[ni][nj] = dp[i][j] + 1;
                G[ni][nj] = 1;
            }
        }
    }
    std::cout << dp[n][m] << '\n';

}