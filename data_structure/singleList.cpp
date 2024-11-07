//
// Created by Wang Jianan on 24-10-1.
// 单链表
#include <iostream>
#include <unordered_map>

struct SingleListNode {
    int data;
    SingleListNode *next;
    explicit SingleListNode(): data(0), next(nullptr){}
    explicit SingleListNode(int data): data(data), next(nullptr){}
};
struct SingleList {
    SingleListNode *head;
    int count;
    std::unordered_map<int, SingleListNode *> map;
    explicit SingleList(SingleListNode *head): head(head), count(0) {
        map[0] = this -> head;
    }
    void insertAhead(int data) {
       insert(map[0], data);
    }

    void deletK(int k) {
        SingleListNode *p = map[k];
        p -> next = p -> next -> next;
    }

    void insertK(int k, int data) {
        insert(map[k], data);
    }

    void insert(SingleListNode *node, int data) {
        ++count;
        auto newNode =  new SingleListNode(data);
        newNode -> next = node -> next;
        node -> next = newNode;
        map[count] = newNode;
    }
    void print() const{
        const SingleListNode *cur = head -> next;
        while(cur != nullptr) {
            std::cout << cur -> data << ' ';
            cur = cur -> next;
        }
    }
};

int main() {
    int M;
    std::cin >> M;
    SingleListNode head;
    SingleList list(&head);
    while(M--) {
        char c;
        std::cin >> c;
        switch(c) {
            case 'H': {
                int x;
                std::cin >> x;
                list.insertAhead(x);
                break;
            }
            case 'D': {
                int k;
                std::cin >> k;
                list.deletK(k);
                break;
            }
            case 'I': {
                int k, x;
                std::cin >> k >> x;
                list.insertK(k, x);
                break;
            }
            default: std::cout << "wrong input" << std::endl;
        }
    }
    list.print();
}