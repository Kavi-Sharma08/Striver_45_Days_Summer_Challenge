#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0 ;
        long long sum1 =0 , sum2 =0 ;
        while(i < gas.size()){
            sum1+=gas[i];
            sum2+=cost[i];
            i++;
        }

        if(sum2 > sum1){
            return -1;
        }

        int j = 0 , start = 0 ;
        long long tank = 0;

        while(j < cost.size()){
            tank = tank + gas[j] - cost[j];
            if(tank <0){
                tank = 0 ;
                start = j + 1;
            }
            j++;
        }
        return start;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int i = 0 , j = 0 , n = cost.size() , tank = 0 ; 

        while(i < gas.size() && j < cost.size()){
            tank = tank + gas[i];
            if(tank <= cost[j]){
                i++;
                j++;
                tank = 0;
                continue;
            }
            else{
                break;
            }
        }
        tank = 0;
        int startIndex = i-1;

        while( (i%n) != startIndex){
            tank = tank + gas[i%n];
            if(tank  >= cost[j%n]){
                tank = tank - cost[j%n];
            }
            else{
                return -1;
            }
            i++;
            j++;
        }
        tank = tank + gas[i%n];
        if(tank  >= cost[j%n]){
            return startIndex + 1;

        }
        return -1;

    }
};
int main(){
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    Solution obj;
    cout<<obj.canCompleteCircuit(gas , cost);
    

}