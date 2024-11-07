//
// Created by Wang Jianan on 24-10-1.
// 双向链表
#include <iostream>
#include <unordered_map>

struct listNode {
    int data;
    listNode *next;
    listNode *prev;
    explicit listNode(int x): data(x), next(nullptr), prev(nullptr) {}
    explicit listNode(int x, listNode *next, listNode *prev): data(x), next(next), prev(prev) {}
};

struct doubleList {
    listNode *head;
    listNode *tail;
    int count;
    std::unordered_map<int, listNode *> map;
    explicit doubleList():count(0) {
        head = new listNode(0);
        tail = new listNode(0);
        head->next = tail;
        head -> prev = nullptr;
        tail -> prev = head;
        tail -> next = nullptr;
    }

    void leftInsert(int);
    void kLeftInsert(int, int);
    void rightInsert(int);
    void kRightInsert(int, int);
    void kDelete(int);
    void InsertL(listNode *, int);
    void InsertR(listNode *, int);
    void print() const;
};

void doubleList::InsertL(listNode *node, int x) {
    ++count;
    auto newNode = new listNode(x);
    listNode *pre = node -> prev;
    pre -> next = newNode;
    node -> prev = newNode;
    newNode -> next = node;
    newNode -> prev = pre;
    map[count] = newNode;
}

void doubleList::InsertR(listNode *node, int x) {
    ++count;
    auto newNode  = new listNode(x);
    node -> next -> prev = newNode;
    newNode -> next = node -> next;
    node -> next = newNode;
    newNode -> prev = node;
    map[count] = newNode;
}

void doubleList::leftInsert(int x) {
    InsertR(head, x);
}

void doubleList::kLeftInsert(int k, int x) {
    InsertL(map[k], x);
}

void doubleList::rightInsert(int x) {
    InsertL(tail, x);
}

void doubleList::kRightInsert(int k, int x) {
    InsertR(map[k], x);
}

void doubleList::kDelete(int k) {
    auto node = map[k];
    auto pre = node -> prev;
    pre -> next = node -> next;
    node -> next -> prev = pre;
    delete node;
}

void doubleList::print() const{
    listNode *cur = head -> next;
    while(cur != tail) {
        std::cout << cur -> data << " ";
        cur = cur -> next;
    }
}


int main() {
    int M;
    std::cin >> M;
    doubleList list;
    std::unordered_map<std::string, int> map = {
        {"L", 1},
        {"R", 2},
        {"D", 3},
        {"IL", 4},
        {"IR", 5}
    };
    while( M --) {
        std::string str;
        std::cin >> str;
        switch(map[str]) {
            case 1: {
                int x;
                std::cin >> x;
                list.leftInsert(x);
                break;
            }
            case 2: {
                int x;
                std::cin >> x;
                list.rightInsert(x);
                break;
            }
            case 3: {
                int k;
                std::cin >> k;
                list.kDelete(k);
                break;
            }
            case 4: {
                int k, x;
                std::cin >> k >> x;
                list.kLeftInsert(k, x);
                break;
            }
            case 5: {
                int k, x;
                std::cin >> k >> x;
                list.kRightInsert(k, x);
                break;
            }
            default: std::cout << "wrong input" << std::endl;
        }
    }
    list.print();
}