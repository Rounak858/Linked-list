#include<iostream>
using namespace std;
struct listNode {
    int val;
    listNode* next;
    listNode() : val(0), next(nullptr) {};
    listNode(int x) : val(x), next(nullptr) {};
    listNode(int x, listNode* next) : val(x), next(next) {} ;
};

class Solution {
    public:
    listNode* addTwoNumbers(listNode* l1, listNode* l2) {
        listNode* dummy = new listNode(); //dummy head
        listNode* result = dummy; //temp pointer to build the list
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum  = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry; // add carry
            carry = sum / 10; // update carry
            listNode* temp = new listNode(sum % 10); // create a new node
            result->next = temp; // add the new node to the result
            result = result->next; // move to the next node
        }
        return dummy->next; // return the result
    }
};

// Helper function to print a linked list
void printList(listNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List 1: 2 -> 4 -> 3  (represents number 342)
    listNode* l1 = new listNode(2, new listNode(4, new listNode(3)));

    // List 2: 5 -> 6 -> 4  (represents number 465)
    listNode* l2 = new listNode(5, new listNode(6, new listNode(4)));

    Solution sol;
    listNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);   // Output should be 7 -> 0 -> 8 (342 + 465 = 807)

    return 0;
}