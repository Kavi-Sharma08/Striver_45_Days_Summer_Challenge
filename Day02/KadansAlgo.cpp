#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0] ;
        for(int i = 1 ; i < nums.size() ; i++){
            if((currSum + nums[i]) > nums[i]){
                currSum = currSum + nums[i];
            }
            else{
                currSum = nums[i];
            }
            maxSum = max(currSum , maxSum);
        }
        return maxSum;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution obj;
    cout<<obj.maxSubArray(nums);
    

}

// TC --> O(N)
// SC --> O(1)