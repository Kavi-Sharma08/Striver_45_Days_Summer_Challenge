#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]++;
        }
        int n = nums.size();
        for(auto it : mpp){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    vector<int> majorityElement2(vector<int>& nums) {
        int count1 =0 , count2 = 0;
        int cand1 = -1  , cand2 = -1 ;
        int n = nums.size();
        for(int i : nums){
            if(count1 == 0){
                cand1 = i;
                count1 = 1;
            }
            else if(count2 == 0){
                cand2 = i;
                count2 = 1;
            }
            else if(i == cand1){
                count1++;
            }
            else if(i == cand2){
                count2++;
            }
            
            else{
                count1--;
                count2--;
            }
        }
        int a = 0 , b = 0 ;
        for(int i : nums){
            if(i == cand1){
                a++;
            }
            if(i == cand2){
                b++;
            }
        }
        if(a > n/3 && b > n/3) {
            if(cand1 == cand2){
                return {cand2};
            }
            return {cand1 , cand2};
        }
        if(a > n/3 && b <= n/3){
            return {cand1};
        }
        if(b > n/3 && a <= n/3){
            return {cand2};
        }
        return {};
        
    }
};

int main(){
    vector<int> nums = {2,2,3,3,3,3,4,4,5,5,6};
    Solution obj;
    vector<int> ans  = obj.majorityElement2(nums);
    for(int i : ans){
        cout<<i<<" ";
    }
}