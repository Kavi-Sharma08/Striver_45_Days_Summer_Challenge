#include<bits/stdc++.h>
using namespace std;
class Item {
public:   
    double val;
    double wt;

    Item(double val , double wt){
        this->val = val;
        this->wt = wt;
    }
};
class Solution {
public:
    bool static comparison(Item* a , Item* b){
        double val1 = (double)(a->val) / (double)(a->wt);
        double val2 = (double)(b->val) / (double)(b->wt);

        return val1 > val2;

    }
    void print(Item* arr[] , int n){
        for(int i = 0 ; i < n ; i++){
            cout<<arr[i]->val<<" "<<arr[i]->wt<<endl;
        }
    }
    double maxProfit(Item* arr[] , int cap , int n){
        sort(arr , arr + n , comparison);
        double maxi =0;
        for(int i = 0 ; i < n ; i++){
            if(cap >= arr[i]->wt){
                maxi+=arr[i]->val;
                cap = cap - arr[i]->wt;
            }
            else if(cap < arr[i]->wt){
                double n1  = cap/arr[i]->wt;
                double n2 = arr[i]->val;
                maxi+=n1*n2;
                break;
                
            }
        }
        return maxi;
    }
};
int main(){
    int n = 5;
    Item* it1 = new Item(50 , 10);
    Item* it2 = new Item(120 , 20);
    Item* it3 = new Item(150 , 30);
    Item* it4 = new Item(210 , 40);
    Item* it5 = new Item(240 , 50);
    Item* arr[n] = { it1 , it2 , it3 ,it4 ,it5};
    double cap = 50;
    Solution obj;
    cout<<obj.maxProfit(arr , cap , n);


}