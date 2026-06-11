#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;

        ListNode* temp  = head;

        int count = 0 ;

        while(count < k){
            if(temp == nullptr) return head;
            temp = temp->next;
            count++;
        }

        ListNode* prevNode = reverseKGroup(temp ,k);
        temp = head , count = 0;

        while(count < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;

    }
};

int main(){
    vector<int> nodes = {1,2,3,4,5};
    int k = 2;
    ListNode* head = createLL(nodes);
    Solution obj;
    ListNode* newHead = obj.reverseKGroup(head , k);
    ListNode* temp = newHead;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;

}