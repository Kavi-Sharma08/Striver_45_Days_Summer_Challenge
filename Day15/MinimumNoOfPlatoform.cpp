#include<bits/stdc++.h>
using namespace std;
class Solution {
public :
    int minNumberPlatForm(vector<int>& nums1 , vector<int> &nums2){
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        int i = 0  , j = 0;
        int maxi = INT_MIN;
        int count = 0;

        while( i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxi = max(maxi , count);
        }
        return maxi;

    }
};
int main(){
    vector<int> nums1 = {900, 945, 955, 1100, 1500, 1800};
    vector<int> nums2 = {920, 1200, 1130, 1150, 1900, 2000};
    Solution obj;
    cout<<obj.minNumberPlatForm(nums1 , nums2);

}