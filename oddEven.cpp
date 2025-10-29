#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x),next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

class Solution{
    public:
    ListNode* oddEven(ListNode* head) {
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution sol;
    ListNode* result = sol.oddEven(head);
    printList(result);
    return 0;
}