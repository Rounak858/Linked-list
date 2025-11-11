#include<iostream>

typedef struct node {
    int data;
    node* next;
    node() : data(0), next(nullptr) {}
    node(int x) : data(x), next(nullptr) {}
    node(int x, node* next) : data(x), next(next) {} 
} node;

node* sortList(node* head) {
    // Time Complexity = O(nLogn) Space Complexity = O(n)
    if(head == nullptr || head->next == nullptr) return head;
    std::vector<int> arr;
    node* temp = head;
    while(temp) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    std::sort(arr.begin(), arr.end());
    temp = head;
    for(int i = 0; i < arr.size(); i++) {
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}
void printList(node* head) {
    while (head)
    {
        std::cout<< head->data;
        if(head->next) std::cout<<"->";
        head = head->next;
    }
    
}
class Solution {
    public:
    node* middleList(node* head) {
        node* slow = head;
        node* fast = head;
        node* prev = nullptr;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    node* mergeLL(node* left, node* right) {
        node* dummyNode = new node(0);
        node* temp = dummyNode;
        while(left && right) {
            if(left->data < right->data) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left) temp->next = left;
        else {
            temp->next = right;
        }
        return dummyNode->next;
    }
    node* sortLL(node* head) {
        if(head == nullptr || head->next == nullptr) return head;
        node* middle = middleList(head);
        node* right = middle->next;
        middle->next = nullptr;
        node* left = head;
        left = sortLL(left);
        right = sortLL(right);
        return mergeLL(left,right);
    }
};
int main() {
    Solution s;
    node* head = new node(4, new node(2, new node(1, new node(3, new node(5)))));
    // node* result = sortList(head);
    node* ans = s.sortLL(head);
    // printList(result);
    printList(ans);
    return 0;
}