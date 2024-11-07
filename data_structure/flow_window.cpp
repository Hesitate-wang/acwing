//
// Created by Wang Jianan on 24-10-8.
//滑动窗口问题 单调队列
#include <iostream>
#include <deque>
#include <vector>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::deque<int> q1, q2;  //分别是最小队列 最大队列
    std::vector<int> v1, v2;
    int nums[n];
    for(int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    for(int i = 0;i < n; ++i) {
        if(i > k - 1) {
            if(nums[i - k] == q1.front()) {
                q1.pop_front();
            }
            if(nums[i - k] == q2.front()) {
                q2.pop_front();
            }
        }
        while(!q1.empty() && nums[i] < q1.back()) {
            q1.pop_back();
        }
        q1.push_back(nums[i]);

        while(!q2.empty() && nums[i] > q2.back()) {
            q2.pop_back();
        }
        q2.push_back(nums[i]);

        if(i >= k - 1) {
            v1.push_back(q1.front());
            v2.push_back(q2.front());
        }
    }
    for(const int &num : v1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for(const int &num : v2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}


