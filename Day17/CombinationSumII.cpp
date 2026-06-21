#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int>&candidates , int target , vector<vector<int>> &ans , vector<int> &currAns , int ind){
        if(target == 0){
            ans.push_back(currAns);
            return;
        }
        if(target < 0 || ind >= candidates.size()){
            return;
        }
        currAns.push_back(candidates[ind]);
        helper(candidates , target - candidates[ind], ans,  currAns, ind + 1);
        currAns.pop_back();
        int i = ind + 1;
        while( i > 0 && i < candidates.size() && candidates[i] == candidates[i-1]){
            i++;
        }
        helper(candidates , target , ans ,currAns , i);

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currAns;
        sort(candidates.begin() , candidates.end());
        helper(candidates ,target , ans , currAns ,0);
        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,2};
    int target = 2;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum2(nums , target);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}