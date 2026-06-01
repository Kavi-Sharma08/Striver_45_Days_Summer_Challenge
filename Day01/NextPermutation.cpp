#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int ind = -1;
        for(int i = size - 2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                ind = i ;
                break;
            }
        }

        for(int i = size - 1 ; i > ind ; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i] , nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1 , nums.end());
    }
};

int main(){
    vector<int> arr = {2 , 1 , 5 , 4 , 3 , 0 , 0};
    Solution obj;
    obj.nextPermutation(arr);
    for(int i : arr){
        cout<<i<<" ";
    }
}

// TC --> O(N)
// SC -- > O(1)