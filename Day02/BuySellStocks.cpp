#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int minValue = nums[0];
        int maxProf = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] < minValue){
                minValue = nums[i];
            }
            maxProf = max(maxProf , (nums[i] - minValue));
        }
        return maxProf;
    }
};

int main(){
    vector<int> nums = {7,6,4,3,1};
    Solution obj;
    cout<<obj.maxProfit(nums);
    

}

// TC --> O(N)
//SC --> O(1)