#include<bits/stdc++.h>
using namespace std;

// TC --> O(N) + O(n*log(n))
//SC --> O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int count = 0 ;
        int majority;

        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0){
                majority = nums[i];
            }
            if(majority == nums[i]){
                count++;
            }
            else {
                count--;
            }
            
        }
        return majority;
    }
};

int main(){
    vector<int> arr = {2,2,1,1,1,2,2};
    Solution obj;
    cout<<obj.majorityElement(arr);

    

}