#include<bits/stdc++.h>
using namespace std;
#include"../Day09/ll.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        ListNode* temp1 = headA;

        while(temp1!=NULL){
            st.insert(temp1);
            temp1 = temp1->next;
        }

        ListNode* temp2 = headB;

        while(temp2!=NULL){
            if(st.find(temp2)!=st.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }

        return NULL;

    }
};