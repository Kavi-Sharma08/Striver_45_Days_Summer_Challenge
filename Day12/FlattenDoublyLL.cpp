#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(){
        this->val = 0;
        this->prev = NULL;
        this->next = NULL;
        this->child = NULL;
    }

    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
        this->child = NULL;
    }
    Node(int val , Node* next){
        this->val = val;
        this->next = next;
        this->prev = NULL;
        this->child = NULL;
    }
    Node(int val , Node* prev , Node* child , Node* next){
        this->val = val;
        this->prev = prev;
        this->next = next;
        this->child = child;
    }
};
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        Node* temp1 = head;

        while(temp1!=NULL){
            if(temp1->child == NULL){
                temp1 = temp1->next;
                continue;
            }

            Node* temp2 = temp1->child;

            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp1->next;
            if(temp1->next !=NULL){
                temp1->next->prev = temp2;
            }
            temp1->next = temp1->child;
            temp1->child->prev = temp1;
            temp1->child = NULL;


        }
        return head;


         


    }
    void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev =  head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;
    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);
    head->next->next->child->next->child->next->prev = head->next->next->child->next->child;
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->prev = head->next->next->child->next;
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->child->next->next->next->prev = head->next->next->child->next->next;




    Solution obj;
    Node* temp = obj.flatten(head);
    obj.print(temp);
    








}