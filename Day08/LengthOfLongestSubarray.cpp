#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums , int k){
    unordered_map<int,int> mpp;
    mpp[0]  = -1;
    int sum = 0 ;
    int maxLen = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];

        if(mpp.find(sum-k)!= mpp.end()){
            maxLen = max(maxLen, i  - mpp[sum - k]);
        }

        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }


    }
    return maxLen;
}

int countSubarrays(vector<int> &nums , int k){
    unordered_map<int,int> mpp;
    int sum = 0 ;
    int count = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];

        if(sum == k){
            count++;
        }

        if(mpp.find(sum - k) != mpp.end()){
            count+=mpp[sum - k];
            
        }
        mpp[sum]++;


    }
    return count;
}

int main(){
    vector<int> nums = {-3, 2 , 1};
    cout<<longestSubarray(nums , 6);
    

}