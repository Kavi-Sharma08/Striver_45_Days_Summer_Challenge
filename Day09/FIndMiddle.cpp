#include<bits/stdc++.h>
#include "./ll.h"

using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next != nullptr){
            slow =slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main(){
    Solution obj;
    vector<int> nodes = {1 , 2  , 3 , 4 , 5 , 6};
    
    ListNode* head = createLL(nodes);

    ListNode* middle = obj.middleNode(head);

    cout<<middle->val;



}