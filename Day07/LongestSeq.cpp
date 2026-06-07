#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n==1) return n;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxSeq = 1;
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int seq = it;
                int count = 1;
                while(st.find(seq + 1)!=st.end()){
                    count++;
                    seq = seq + 1;
                }
                maxSeq = max(maxSeq , count );
            }
        }
        return maxSeq;
    }
};

int main(){

    vector<int> nums = {100,4,200,1,3,2};
    Solution obj;
    cout<<obj.longestConsecutive(nums);

}