#include<bits/stdc++.h>
using namespace std;

// TC --> O(m*logn*n) + O(m)
// SC --> O(m*n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums[0]);

        for(int i = 1 ; i < nums.size() ; i++){
            vector<int> vec = nums[i];
            int index0 = vec[0];
            int index1 = vec[1];

            int val1 = ans[ans.size()-1][0];
            int val2 = ans[ans.size()-1][1];
            if(index0 >= val1 && index0 <= val2){
                ans.pop_back();
                if(val2 > index1){
                    ans.push_back({val1 , val2});
                }
                else ans.push_back({val1 , index1});
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;

    }
};

int main(){
    vector<vector<int>> arr = {
        {1,4},
        {2,3}
    };
    Solution obj;
    vector<vector<int>> ans = obj.merge(arr);
    for(vector<int> i : ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

}

