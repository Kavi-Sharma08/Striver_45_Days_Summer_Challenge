#include<bits/stdc++.h>
using namespace std;

// TC --> O(log(m*n)) + O(log(n))
// SC --> O(1)

class Solution {
public:
    bool binarySearch(vector<int> &nums , int target){
        int low = 0 ;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid] > target){
                high = mid -1;
            }
            else if(nums[mid] < target){
                
                low = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size();
        int n = nums[0].size();

        int low = 0 ;
        int high = m-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(target >= nums[mid][0] && target <= nums[mid][n-1]){
                return binarySearch(nums[mid] , target);
            }
            else if(target < nums[mid][0]){
                high = mid -1;
            }
            else if(target > nums[mid][n-1]){
                low = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> nums = {
        {1,3}
    };
    Solution obj;
    cout<<obj.searchMatrix(nums , 3);
    

}