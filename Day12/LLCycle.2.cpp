#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                break;
            }
        }
        
        if(fast != slow) return nullptr;

        slow = head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};
