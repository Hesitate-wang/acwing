//
// Created by Admin on 2024/9/9.
//

#include<iostream>


void quickSort(int nums[], int l, int r){
    if(l >= r){
        return;
    }
    int mid = (l + r) >> 1;
    int left = l, right = r;
    int pivot = nums[mid];
    while(left<right){
        while(nums[left]<pivot){
            ++left;
        }
        while(nums[right]>pivot){
            --right;
        }
        if(left < right){
            std::swap(nums[left], nums[right]);
        }
    }
    quickSort(nums, )


}
int main(){
    int n = 0;
    std::cin >> n;
    int nums[n];
    for(int i = 0; i < n; ++i){
        std::cin >> nums[i];
    }
    quickSort(nums, 0, n-1);
}