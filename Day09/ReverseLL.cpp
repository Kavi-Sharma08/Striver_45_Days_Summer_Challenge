#include<bits/stdc++.h>
#include "./ll.h"

using namespace std;

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
};

int main(){
    vector<int> nodes = {1,2,3,4,5};

    ListNode* head =  createLL(nodes);
    Solution obj;
    ListNode* reverseHead = obj.reverseList(head);
    ListNode* temp = reverseHead;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;



    

}