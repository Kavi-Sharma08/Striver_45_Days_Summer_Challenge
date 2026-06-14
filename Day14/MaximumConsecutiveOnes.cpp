#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = INT_MIN;
        int count = 0;
        for(int i : nums){
            if(i == 1){
                count+=1;
            }
            else{
                maxi = max(count , maxi);
                count=0;
            }
        }
        return max(count,maxi);
    }
};

int main(){
    vector<int> nums = {1,1,0,1,1,1};
    Solution obj;
    cout<<obj.findMaxConsecutiveOnes(nums);
}