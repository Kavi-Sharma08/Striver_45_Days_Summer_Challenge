#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* currNext = curr->next;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            
            curr->next = prev;
            prev = curr;
            curr = currNext;

            if(currNext!=nullptr){
                currNext = currNext->next;
            }
        }
        head = prev;
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2==nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode* head1 = l2;
        ListNode* head2 = l1;

        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;
        int carry = 0 ;
        while(head1 != nullptr && head2 != nullptr){
            int sum = head1->val + head2->val + carry;
            carry = 0;
            if(sum >=10 && sum < 20){
                carry = sum/10;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            tail->next = newNode;
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1!=nullptr){
            int sum = head1->val + carry;
            carry = 0;
            if(sum >=10 && sum < 20){
                carry = sum/10;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            tail->next = newNode;
            tail = tail->next;
            head1 = head1->next;

        }
        while(head2!=nullptr){
            int sum = head2->val + carry;
            carry = 0;
            if(sum >=10 && sum < 20){
                carry = sum/10;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            tail->next = newNode;
            tail = tail->next;
            head2 = head2->next;

        }
        if(carry){
            ListNode* newNode = new ListNode(carry); 
            tail->next = newNode;
            tail = tail->next;
        }
        return dummyHead->next;

    }
};

int main(){
    vector<int> nodes1 = {2,4,9};
    vector<int> nodes2 = {5,6,4,9};
    ListNode* head1 = createLL(nodes1);
    ListNode* head2 = createLL(nodes2);
    Solution obj;

    ListNode* head = obj.addTwoNumbers(head1 , head2);

    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
    

}