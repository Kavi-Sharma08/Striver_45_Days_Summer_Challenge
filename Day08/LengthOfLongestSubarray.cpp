#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums){
    unordered_map<int,int> mpp;
    int sum = 0 ;
    int maxLen = -1;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];

        if(sum == 0){
            maxLen = i+1;
        }

        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
        else{
            maxLen = max(maxLen , i - mpp[sum]);
        }


    }
    return maxLen;
}
int main(){
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    cout<<longestSubarray(nums);
    

}