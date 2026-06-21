#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void subsets(vector<int> &nums , int ind , int currSum , vector<int>&ans){
        if(ind >= nums.size()){
            ans.push_back(currSum);
            return;
        }
        subsets(nums , ind + 1 , currSum + nums[ind] , ans);
        subsets(nums , ind + 1 , currSum , ans);
    }
};
int main(){
    vector<int> nums = {3,1,2};
    Solution obj;
    vector<int> ans;
    obj.subsets(nums , 0 , 0 , ans);
    sort(ans.begin() , ans.end());
    for(int i : ans){
        cout<<i<<" ";
    }
}