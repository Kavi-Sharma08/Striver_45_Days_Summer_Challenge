#include<bits/stdc++.h>
#include "./ll.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;

        while(list1 != nullptr && list2 != nullptr){

            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;

            }
            else if(list2->val < list1->val){
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;

            }
        }
        while(list1!=nullptr){
            tail->next = list1;
            list1  = list1->next;
            tail = tail->next;
        }

        while(list2!=nullptr){
            tail->next = list2;
            list2  = list2->next;
            tail = tail->next;
        }

        return head->next;
    }
};

int main(){
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,4};
    ListNode * head1 = createLL(nums1);
    ListNode* head2 = createLL(nums2);

    Solution obj;

    ListNode* head = obj.mergeTwoLists(head1 , head2);
    cout<<head->val;
}