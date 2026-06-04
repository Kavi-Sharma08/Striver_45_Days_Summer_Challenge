#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0 ;
        while(i < nums.size()){
            int correctIndex = nums[i]-1;
            if(i!=correctIndex){
                if(nums[i] == nums[correctIndex]){
                    return nums[i];
                }
                else swap(nums[i] , nums[correctIndex]);
            }
            else i++;
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {1,3,4,2,3};
    Solution obj;
    cout<<obj.findDuplicate(arr);
    

}