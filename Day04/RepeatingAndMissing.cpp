#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> nums = {3, 5, 4, 1, 1};
    vector<int> ans;
    int repeatValue = -1 ;
    int i = 0 ;
    while(i < nums.size()){
        int correctIndex = nums[i]-1;
        if(i!=correctIndex){
            if(nums[i] == nums[correctIndex]){
                ans.push_back(nums[i]);
                break;
            }
            else swap(nums[i] , nums[correctIndex]);
        }
        else i++;
    }
    for(int i = 0 ; i < nums.size() ; i++){
        if((nums[i]-1) != i){
            ans.push_back(i+1);
        }
    }
    for(int i : ans){
        cout<<i<<" ";
    }

}