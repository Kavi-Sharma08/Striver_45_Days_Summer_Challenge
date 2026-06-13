#include<bits/stdc++.h>
using namespace std;

class Node{
public:  
    int val;
    Node* next;
    Node* random;

    Node(int val){
        this->val = val;
        this->random = NULL;
        this->next = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            Node* originalNext = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = originalNext;
            temp = copy->next;

        }
        temp = head;
        while(temp != NULL){

            if(temp->random){
                temp->next->random = temp->random->next;
            }
            else{
                temp->next->random = NULL;
            }
           
            temp = temp->next->next; 
        }

        temp = head;

        Node* head2 = new Node(-1);

        Node* dummyNode = head2;

        while(temp != NULL){
            Node* copy = temp->next;

            dummyNode->next = copy;
            dummyNode = dummyNode->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return head2->next;

        

    }
};

int main(){

    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(12);

    
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Solution obj;
    Node* head2 = obj.copyRandomList(head);
    while(head2!=NULL){
        cout<<head2->val<<" ";
        head2 = head2->next;
    }



}