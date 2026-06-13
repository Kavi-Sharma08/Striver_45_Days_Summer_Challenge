#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:
    ListNode* reverseLL(ListNode* head , int count){
        ListNode* curr = head;
        ListNode* currNext = head->next;
        ListNode* prev = nullptr;

        while(curr!=nullptr && count!=0){
            curr->next = prev;
            prev = curr;
            curr  = currNext;
            if(currNext!=nullptr){
                currNext = currNext->next;
            }
            count--;
            
        }
        head = prev;
        return head;
    }
    int countLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == nullptr || head->next == nullptr) return head;
        
        int count = countLength(head);

        if(k >= count) {
            k = k%count;
        }
        
        if(k==0) return head;

        ListNode* reverseHead = reverseLL(head , count);
        ListNode* h1 = reverseHead;
        
        int c3 = 0;

        while(c3 < k){
            h1 = h1->next;
            c3++;
        }

        ListNode* h2 = reverseLL(reverseHead , k);
        ListNode* h3 = reverseLL(h1 , count-k);

        reverseHead->next = h3;

        return h2;
    }
};
int main(){
    vector<int> nodes = {1,2,3,4,5};
    ListNode* head = createLL(nodes);
    Solution obj;
    ListNode* newHead= obj.rotateRight(head , 4);
    ListNode* temp = newHead;

    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    

}