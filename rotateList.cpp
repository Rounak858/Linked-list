#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node() : data(0), next(nullptr){}
    node(int x) : data(x), next(nullptr) {}
    node(int x, node* next) : data(x), next(next){}
};

class Solution
{
    public:
    node* rotateList(node* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        for(int i = 0; i < k; i++) {
            node* temp = head;
            while(temp->next->next != nullptr) { //find the second last node
                temp = temp->next;
            }
            node* end = temp->next;//store the last node
            temp->next = nullptr;
            end->next = head;   //link the last node to the head
            head = end;
        }
        return head;
    }
    // void printList(node* head);
};
void printList(node* head) {
        while(head) {
            cout<<head->data;
            if (head->next) cout << " -> ";
                head = head->next;
        }
        cout<<endl;
    }

    class Solution2{
        public:
        node* rotateright(node* head, int k) {
            // Time Compplexity = O(N) Space Complexity = O(1)
            if(head == nullptr || head->next == nullptr || k == 0) {return head;}
            int length = 1;
            node* temp = head;
            while(temp->next != nullptr) {
                length++; // count the number of nodes
                temp = temp->next;
            }
            temp->next = head;
            k = k % length; // handle the case where k is greater than the length of the list
            int end = length - k; // find the end of the rotated list
            while(end--) {
                temp = temp->next;
            }
            head = temp->next;
            temp->next = nullptr;
            return head;
        }
    };
int main() {
    node* head = new node(1, new node(2, new node(3, new node(4, new node(5)))));
    Solution sol;
    Solution2 sol2;
    // node* result = sol.rotateList(head, 2);
    node* result2 = sol2.rotateright(head,2);
    // printList(result);
    printList(result2);
    return 0;
}
