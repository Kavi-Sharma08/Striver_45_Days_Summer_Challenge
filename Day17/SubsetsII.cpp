#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int> &nums , vector<vector<int>> &ans ,vector<int> &currAns ,int ind){
        if(ind >= nums.size()){
            ans.push_back(currAns);
            return;
        }
        currAns.push_back(nums[ind]);
        helper(nums , ans , currAns , ind +1);
        currAns.pop_back();
        int index = ind + 1;
        while(index < nums.size() && nums[index] == nums[index-1] ){
            index++;

        }
        helper(nums , ans , currAns , index);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> currAns;
        helper(nums ,ans , currAns , 0);
        for(vector<int> i : ans){
            for(int j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }


    }
};
int main(){
    vector<int> nums = {1,2,2};
    Solution obj;
    obj.subsetsWithDup(nums);


    

}