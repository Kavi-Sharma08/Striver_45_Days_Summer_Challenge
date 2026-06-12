#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2) {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* head1 , ListNode* head2){
        ListNode* newHead = new ListNode(-1);
        ListNode* dummy = newHead;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->val < head2->val){
                dummy->child = head1;
                dummy = head1;
                head1 = head1->child;
            }
            else{
                dummy->child = head2;
                dummy = head2;
                head2 = head2->child;
            }
            dummy->next = nullptr;
        }
        if(head1){
            dummy->child = head1;
        }
        else {
            dummy->child = head2;
        }
        if(newHead->child){
            newHead->child->next = nullptr;
        }

        return newHead->child;

    }
    ListNode* flatten(ListNode* head){
        if(head==nullptr || head->next == nullptr) return head;

        ListNode* newHead = flatten(head->next);

        head = merge(head , newHead);

        return head;
    }

};

int main(){
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    Solution obj; 

    ListNode* flattened = obj.flatten(head);
}