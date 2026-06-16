#include<bits/stdc++.h>
using namespace std;
class Job{
public:    
    int id;
    int deadLine;
    int profit;
    Job(int id , int deadLine , int profit){
        this->id = id;
        this->deadLine = deadLine;
        this->profit = profit;
    }
    
};
class Solution {
public:
    static bool comparison(Job* a,Job* b) {
        return a->profit > b->profit; 
    }
    void jobSort(Job* arr[] , int n){
        sort(arr , arr + n , comparison);
    }
    void print(Job* arr[] , int n){
        for(int i = 0 ; i < n ; i++ ){
            cout<<arr[i]->id<<" "<<arr[i]->deadLine<<" "<<arr[i]->profit<<endl;
        }
    }
    int maxDeadline(Job* arr[] , int n){
        int maxDead = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            maxDead = max(maxDead , arr[i]->deadLine);
        }
        return maxDead;
    }
    vector<int> maxProfit(Job* arr[] , int n){
        int maxi = maxDeadline(arr , n);
        int nums[maxi+1];
        for(int i = 0 ; i < n ; i++){
            nums[i] = -1;
        }
        int maxProfitEarned = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[arr[i]->deadLine] == -1){
                maxProfitEarned+=arr[i]->profit;
                nums[arr[i]->deadLine] = arr[i]->id;
            }
            else{
                int indexValue = arr[i]->deadLine;
                while(indexValue > 0){
                    if(nums[indexValue] == -1){
                        maxProfitEarned+=arr[i]->profit;
                        nums[indexValue] = arr[i]->id;
                        break;
                    }
                    indexValue--;
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]!=-1){
                count++;
            }
        }
        return {count , maxProfitEarned};
    }

};
int main(){
    int n = 5;
    Job* job1 = new Job(1, 2, 100);
    Job* job2 = new Job(2, 1, 19);
    Job* job3 = new Job (3, 2, 27);
    Job* job4 = new Job(4, 1, 25);
    Job* job5 = new Job(5, 1, 15);
    Job* arr[] = {job1 , job2 , job3 , job4 , job5};
    Solution obj;
    obj.jobSort(arr,n);
    vector<int> ans = obj.maxProfit(arr , n);
    for(int i : ans){
        cout<<i<<" ";
    }
    

}