#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int merge(vector<long long> &nums , int low , int mid , int high){
        vector<int> temp;
        int count = 0;
        int left = low;
        int right = mid +1;

        int j = mid +1;
        for(int i = low ;  i <= mid ; i++){
            while(j <= high && nums[i] > 2*nums[j]){
                j++;
            }
            count = count + (j - (mid + 1));
        }
        while(left <= mid && right <= high){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left  <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low ; i <= high  ; i++){
            nums[i] = temp[i-low];
        }
        return count;
    }
    int mergeSort(vector<long long> &nums , int low , int high){
        int count = 0;

        if(low >= high) return count;

        int mid = low + (high - low)/2;

        count+=mergeSort(nums , low , mid);
        count+=mergeSort(nums , mid + 1 , high);
        count+=merge(nums , low , mid , high);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<long long> arr(nums.begin(), nums.end());;
        return mergeSort(arr , 0 , nums.size()-1);
    }
};

int main(){

    vector<int> nums = {1,3,2,3,1};
    Solution obj;
    cout<<obj.reversePairs(nums)<<endl;
}