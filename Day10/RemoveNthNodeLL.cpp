#include<bits/stdc++.h>
using namespace std;
#include "../Day09/ll.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        if(n==1 && count == 1) return nullptr;
        int removeFromStart = count - n;
        temp = head;
        count = 0;
        while(temp != nullptr) {
            if(removeFromStart == 0) {
                return head->next;
            }
            count++;
            if(count == removeFromStart){
                if(temp->next->next){
                    temp->next = temp->next->next;
                }
                else{
                    temp->  next = nullptr;
                }
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
int main(){
    vector<int> nodes = {1,2};
    ListNode* head = createLL(nodes);
    Solution obj;
    ListNode* newHead = obj.removeNthFromEnd(head , 1);
    ListNode* temp = newHead;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    
    
    return 0;

    

}