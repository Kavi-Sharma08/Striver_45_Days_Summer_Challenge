#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            int value = target - nums[i];
            if(mpp.find(value)==mpp.end()){
                mpp[nums[i]] = i;
            }
            else{
                return {i , mpp[value]};
            }
        }
        return {-1,-1};
    }
};
int main(){
    vector<int> nums = {2,7,11,15};
    Solution obj;
    obj.twoSum(nums , 9);

}