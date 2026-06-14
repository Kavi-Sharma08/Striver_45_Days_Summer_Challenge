#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxToLeft(vector<int> &arr){
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i = 1 ; i < arr.size() ; i++){
            if(ans[i-1] >= arr[i]){
                ans.push_back(ans[i-1]);
            }
            else if(arr[i] > ans[i-1]){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
    vector<int> maxToRight(vector<int> &arr){
        int size = arr.size()-1;
        vector<int> ans(size + 1);
        ans[size] = arr[size];
        for(int i = size-1 ; i >= 0 ; i--){
            if(ans[i+1] >= arr[i]){
                ans[i] = ans[i + 1];
            }
            else if(arr[i] > ans[i+1]){
                ans[i] = arr[i];

            }


        }
        return ans;

    }
    int helper(vector<int> &arr){
        vector<int> left = maxToLeft(arr);
        vector<int> right =maxToRight(arr);
        vector<int> minOfLeftRight;
        for(int i = 0 ; i < left.size() ; i++){
            int minimum = min(left[i] , right[i]);
            minOfLeftRight.push_back(minimum);
        }
        int sum = 0;
        for(int i = 0 ; i < minOfLeftRight.size() ; i++){
            sum = sum + (minOfLeftRight[i]-arr[i]);
        }
        return sum;
    }
    int trap(vector<int>& height) {
        return helper(height);
        
    }
};

int main(){
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution obj;
    cout<<obj.trap(nums);
    

}