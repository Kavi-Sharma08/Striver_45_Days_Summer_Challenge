#include<bits/stdc++.h>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode* next;
    ListNode* child;

    ListNode(){
        val = 0 ;
        next = NULL;
        child = NULL;
    }

    ListNode (int val){
        this->val = val;
        this->child = NULL;
        this->next = NULL;
    }

    ListNode(int val , ListNode* next , ListNode* child){
        this->val = val;
        this->next = next;
        this->child = child;
    }

    
};

class Solution {

public:
    ListNode* merge(ListNode* list1 , ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res->child = list1;
                list1 = list1->child;
            }
            else{
                res->child = list2;
                list2 = list2->child;
            }
            res = res->child;
        }
        if(list1){
            res->child = list1;
            res = res->child;
        }
        if(list2){
            res->child = list2;
            res = res->child;
        }

        return dummyNode->child;
    }
    ListNode* flatten(ListNode* head){

        if(head == NULL) return head;

        ListNode* newHead = flatten(head->next);
        ListNode* newHead2 =  merge(newHead , head);

        return newHead2;
    }
    void print(ListNode *head){

        if(head == NULL) return ;

        ListNode* temp = head;

        cout<<temp->val<<endl;

        while(temp->child  != NULL){
            cout<<temp->child->val<<endl;
            temp = temp->child;
        }

        print(head->next);
    }
    void print2(ListNode* head){
        while(head != NULL){
            cout<<head->val<<" ";
            head = head->child;
        }
    }
};

int main(){

    ListNode* head = new ListNode(4);
    head->child = new ListNode(10);
    head->next = new ListNode(2);

    head->next->child = new ListNode(5);
    head->next->child->child = new ListNode(20);

    head->next->next = new ListNode(12);

    head->next->next->child = new ListNode(13);
    head->next->next->child->child = new ListNode(16);
    head->next->next->child->child->child = new ListNode(17);

    Solution obj;

    ListNode* newHead = obj.flatten(head);

    obj.print2(newHead);

    

    

}