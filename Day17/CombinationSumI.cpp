#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int> &cand , int target , vector<int> &currAns , vector<vector<int>> &ans , int ind ){
        if(target == 0){
            ans.push_back(currAns);
            return;
        }
        if(target < 0){
            return ;
        }
        if(ind >= cand.size()){
            return;
        }
        currAns.push_back(cand[ind]);
        helper(cand , target - cand[ind] , currAns , ans , ind);
        currAns.pop_back();
        helper(cand , target , currAns , ans , ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currAns;
        vector<vector<int>> ans;
        helper(candidates , target , currAns , ans , 0);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> cand = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = obj.combinationSum(cand , target);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}