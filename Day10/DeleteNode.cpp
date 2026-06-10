#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:

    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;

    }
};

int main(){
    vector<int> nodes = {4,5,1,9};
    int node = 1;
    ListNode* head = createLL(nodes);
    ListNode* temp = head;
    while (temp->val != node) {
        temp = temp->next;
    }
    Solution obj;
    obj.deleteNode(temp);
    ListNode* temp2 = head;
    while (temp2 != nullptr) {
        cout<<temp2->val<<" ";
        temp2 = temp2->next;
    }
    
    
    return 0;

    

}