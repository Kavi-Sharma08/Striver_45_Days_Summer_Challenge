#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* currNext = curr->next;
        ListNode* prev = nullptr;

        while(curr!=nullptr){
            curr->next = prev;
            prev = curr;
            curr = currNext;

            if(currNext!=nullptr){
                currNext = currNext->next;
            }
        }
        head = prev;
        return head;
    }
    ListNode* middle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=nullptr &&  fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome2(ListNode* head) {
        ListNode* middleNode = middle(head);
        ListNode* tail = reverseLL(middleNode);

        while(tail!=nullptr && head!=nullptr){
            if(tail->val != head->val){
                return false;
            }
            tail = tail->next;
            head = head->next;
        }
        return head==nullptr || tail == nullptr;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* tail = head;
        vector<int> arr;
        while(tail!=nullptr){
            arr.push_back(tail->val);
            tail = tail->next;
        }
        for(int i = 0 , j = arr.size() -1 ; i <= j ; i++ , j--){
            if(arr[i]!=arr[j]) return false;
        }

        return true;
    }
};

int main(){

    vector<int> nodes = {1,2,2,1};
    ListNode* head = createLL(nodes);
    
    Solution obj;
    cout<<obj.isPalindrome2(head);

    return 0;
}
