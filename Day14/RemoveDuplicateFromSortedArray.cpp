#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(prev == -1){
                prev++;
            }
            else{
                if(nums[i] != nums[prev]){
                    prev++;
                    nums[prev] = nums[i]; 
                }
            }
        }
        return prev + 1;
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3};
    Solution obj;
    int ans = obj.removeDuplicates(nums);
    for(int i = 0 ; i < ans ; i++){
        cout<<nums[i]<<" ";
    }
    

}