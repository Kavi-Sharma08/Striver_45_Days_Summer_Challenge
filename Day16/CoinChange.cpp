#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>& coins, int amount , int ind , vector<vector<int>>&dp){
        int INF = 1e9;
        if(amount == 0) return 0;
        if(ind >= coins.size()) return INF;

        if(dp[ind][amount] !=-1){
            return dp[ind][amount];
        }
        
        int pick = INF ;

        if(coins[ind] <= amount){
            pick = 1 + helper(coins , amount - coins[ind] , ind , dp);
        }
        
        int non_pick = helper(coins , amount , ind +1 , dp);

        return dp[ind][amount] = min(pick , non_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 ,-1));
        return helper(coins , amount , 0 , dp);
    }
};

int main(){
    vector<int> nums = {186,419,83,408};
    int amount = 6249;
    Solution obj;
    cout<<obj.coinChange(nums , amount);
}