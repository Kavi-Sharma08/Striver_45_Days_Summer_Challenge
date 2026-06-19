#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int> &nums , vector<vector<int>> &ans ,int ind){
        if(ind >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind ; i < nums.size() ; i++){
            swap(nums[ind] , nums[i]);
            helper(nums , ans , ind +1);
            swap(nums[ind] , nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums , ans , 0);
        return ans;
    }
};
int main(){
    vector<int> nums = {1,2,3};
    Solution obj;
    vector<vector<int>> ans = obj.permute(nums);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

}