#include<vector>
#include"ll.h"

ListNode* createLL(vector<int> &nums){
    ListNode* head;
    ListNode* prev = nullptr;
    ListNode* temp;
    for(int i = 0 ; i < nums.size() ; i++ ){
        ListNode* node = new ListNode(nums[i]);
        if(i ==0){
            head = node;
            prev = head;
        }
        else {
            prev->next = node;
            prev = node;
        }
    }
    return head;
}