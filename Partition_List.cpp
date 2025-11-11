#include<iostream>

typedef struct node {
    int data;
    node* next;
    node() : data(0), next(nullptr) {}
    node(int x) : data(x), next(nullptr) {}
    node(int x, node* next) : data(x), next(next) {} 
} node;

class Solution {
    public:
    node* partionList(node* head, int k) {
        // Time Complexity = O(N) Space Complexity = O(1)
        if(head == nullptr || head->next == nullptr) return head;
        node* SmallList = new node(0, nullptr);
        node* LargeList = new node(0, nullptr);
        node* small = SmallList;
        node* large = LargeList;
        while(head) {
            if(head->data < k) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = LargeList->next;
        return SmallList->next;
    }
};
void printList(node* head) {
    while(head) {
        std::cout<<head->data;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout<<std::endl;
}

int main() {
    node* head = new node(1, new node(4, new node(3, new node(2, new node(5, new node(2))))));
    Solution sol;
    node* result = sol.partionList(head, 3);
    printList(result);
    return 0;
}