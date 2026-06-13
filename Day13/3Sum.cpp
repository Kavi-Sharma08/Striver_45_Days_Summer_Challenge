#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == target){ //found the sum remove the duplicate
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(k < nums.size() && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }

            }

        }
        return ans;
    }
};

int main(){
    vector<int> nums = {0,0,0,0};
    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}