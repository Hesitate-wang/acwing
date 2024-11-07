//
// Created by Wang Jianan on 24-9-23.
//
#include <iostream>

int bitCal(int a) {
    int res = 0;
    while(a != 0 ) {
        if(a % 2 != 0) {
            ++res;
        }
        a = a >> 1;
    }
    return res;
}
int main() {
    int n;
    std::cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int res[n + 1];
    for(int i = 0; i < n; i++) {
        res[i] = bitCal(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        std::cout << res[i] << " ";
    }

}