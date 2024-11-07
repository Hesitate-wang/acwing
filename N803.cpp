//
// Created by Wang Jianan on 24-9-26.
//
//区间合并

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
const int SZ = 1e5+1;
std::unordered_map<int, int> map;

int main() {
    int n, m = 0;
    scanf("%d",&n);
    m = n;
    int pa[SZ];
    for(int i=0;i<n;++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        if(map.count(l) == 0) {
            map[l] = r;
            pa[i] = l;
        }else {
            --m;
            map[l] = std::max(map[l], r);   //map.embrace() 不会插入已经存在的键
        }
    }
    std::sort(pa, pa + m);
    int end = INT_MIN, ans = 0;
    for(int i=0;i<m;++i) {
        int right = map[pa[i]];
        if(pa[i] > end) {
            ++ans;
        }
        end = std::max(end, right);
    }
    printf("%d\n", ans);
}
