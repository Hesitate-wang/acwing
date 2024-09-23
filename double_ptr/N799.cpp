//
// Created by Wang Jianan on 24-9-23.
//
//最长连续不重复子序列

#include <iostream>
#include <unordered_map>

const int N = 1e5 + 1;
int main() {
    int n;
    std::cin >> n;
    int nums[N];
    for ( int i=0; i<n; i++ ) {
        std::cin >> nums[i];
    }
    int i = -1, j = 0, res = 0;
    std::unordered_map<int, int> map;
    while ( j < n ) {
        if(map.count(nums[j]) != 0 && map[nums[j]] > i) {
            res = std::max(res, j - i - 1);
            i = map[nums[j]];
        }
        map[nums[j]] = j;  //无论是否出现重复 都需要更新位置
        ++j;
    }
    res = std::max(res, j - i - 1);  //循环结束 最后一个元素也没有重复
    std::cout << res << std::endl;
}