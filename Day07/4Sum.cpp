#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int i = 0 ;

        while( i < nums.size()){

            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }

            int j = i +1;

            while(j < nums.size()){

                int k = j+1;
                int l = nums.size() - 1;

                while(k < l){

                    long long sum = (long long) nums[i] + (long long) nums[j] +(long long) nums[k] + nums[l];

                    if(sum == target){
                        ans.push_back({nums[i] , nums[j] , nums[k] , nums[l]});
                        k++;
                        l--;
                        while(k < l  && nums[k] == nums[k-1]){
                            k++;

                        }
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                    
                }
                j++;
                while( j < nums.size() && nums[j] == nums[j-1]){
                    j++;
                }
                    
            }         
            
            i++;




        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = obj.fourSum(nums , target);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

}