#include<bits/stdc++.h>
using namespace std;


//TC --> O(nlogn) + o(n)
//SC --> O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m , j = 0 ; i < nums1.size() , j < nums2.size() ; i++ , j++){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin() , nums1.end());
        for(int i : nums1){
            cout<<i<<" ";
        }
    }
};

int main(){
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0;
    int n = 1;
    Solution obj;
    obj.merge(nums1 , m , nums2 , n);
    

}