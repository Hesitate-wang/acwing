//
// Created by Admin on 2024/9/19.


#include<iostream>

const int N = 1001;
int main(){
    int n, m, q;
    std::cin >> n >> m >> q;
    int matrix[N][N];
    int prefix[N][N];
    for(int i = 1;i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            std::cin >> matrix[i][j];
        }
    }
    for(int i=1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + matrix[i][j];

    while(q--){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << (prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1]) << std::endl;
    }

}