//
// Created by Wang Jianan on 24-9-24.
//
// 离散化求区间和
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> vec;   //坐标映射
std::vector<std::pair<int, int>> add, query;  // 操作向量记录

int find_index(std::vector<int> &vec, int target) {  //别忘了使用引用传递
    int l = 0, r = vec.size();

    while( l < r) {
        int mid = (l + r) >> 1;
        if( vec[mid] >= target) {
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        int x, c;
        scanf("%d %d", &x, &c);
        vec.push_back(x);
        add.emplace_back(x, c);
    }
    for(int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        query.emplace_back(l, r);
        vec.push_back(l);
        vec.push_back(r);
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    int sz = vec.size();
    int arr[sz + 1] = { 0 };
    for(auto it : add) {
        int index = find_index(vec, it.first);
        arr[index] += it.second;
    }
    int prefix[sz + 1] = { 0 };
    for(int i = 1; i <=sz; ++i) {
        prefix[i] = prefix[i - 1] + arr[i-1];
    }
    for(auto it : query) {
        int l = find_index(vec, it.first);
        int r = find_index(vec, it.second);
        int res = prefix[r + 1] - prefix[l];
        printf("%d\n", res);
    }
}