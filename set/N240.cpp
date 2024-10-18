//
// Created by Wang Jianan on 24-10-18.
//食物链
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> vec(50001);  //A B C 集合
std::unordered_map<int, int> ate;   //被捕食者 捕食者
std::unordered_map<int, int> eat;   //捕食者 被捕食者
int inChain[50001];


int search(const int x) {
    return x == vec[x]? x: vec[x] = search(vec[x]);
}
void connect(int a, int b) {
    int x = vec[a];
    int y = vec[b];
    if(x!=y) {
        vec[y] = x;
    }
}

int main() {
    int N, K, ans = 0;
    std::cin >> N >> K;
    for(int i = 0;i < 50001; ++i) {
        vec[i] = i;
        inChain[i] = 0;
    }
    while(K --) {
        int D, X, Y;
        std::cin >> D >> X >> Y;
        if(X > N || Y > N) {
            ++ans;
            continue;
        }
        if(D == 1) {
            //X Y 是同类 检查是否冲突
            int x = search(X);
            int y = search(Y);
            if(inChain[X] && inChain[Y] && ((eat[x] && eat[x] == y)
                || (eat[y] && eat[y] == x))) {
                //如果X Y 已经加入食物链 且确定x->y or x->z-y(y->x) 则不是同类
                ++ans;
            }else {
                //真话
                inChain[X] = inChain[Y] = 1;
                connect(x, y);

                //食物链关系转移
                if(eat[y] && eat[x]) {
                    connect(eat[x], eat[y]);
                }else if(eat[y]) {
                    eat[x] = eat[y];
                }
                if(ate[x] && ate[y]) {
                    connect(ate[x], ate[y]);
                }else if(ate[y]) {
                    ate[x] = ate[y];
                }
            }
        }else {
            //X 吃 Y 检查是否冲突
            int x = search(X);
            int y = search(Y);
            if(x == y ||
                (inChain[X] && inChain[Y] &&
                        eat[y] && eat[y] == x)) {
                //如果已经加入食物链 且明确x->z->y or y -> x 则假话
                ++ans;
            }else {
                //建立捕食关系
                if(!inChain[X] && !inChain[Y]) {
                    ate[y] = x;
                    eat[x] = y;
                    inChain[X] = inChain[Y] = 1;
                }else if(!inChain[X]) {
                    inChain[X] = 1;
                    if(ate[y]) {
                        connect(x, ate[y]);
                    }else {
                        ate[y] = x;
                        eat[x] = y;
                    }
                }else if(!inChain[Y]) {
                    inChain[Y] = 1;
                    if(eat[x]) {
                        connect(eat[x], y);
                    }else {
                        eat[x] = y;
                        ate[y] = x;
                    }
                }else {
                    ate[y] = x;
                    eat[x] = y;
                }
            }
        }

    }
    std::cout << ans <<std::endl;
}
