#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<string> &curr , vector<vector<string>> &res , vector<vector<bool>> &dp , int ind , string &s){
        if(ind >= s.length()){
            res.push_back(curr);
            return;

        }

        for(int i = ind ; i < s.length() ; i++){
            if(dp[ind][i]){
                curr.push_back(s.substr(ind , i - ind +1));
                helper(curr , res , dp , i+1 , s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n , vector<bool> (n , false));
        for(int l =1 ; l <= n ; l++){
            for(int i = 0 ; i <= n-l ; i++){
                int j = i+l-1;
                if(i==j){
                    dp[i][j] = true;
                }
                else if(j==i+1){
                    dp[i][j] = (s[i]==s[j]);
                }
                else if (s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        vector<string> curr;
        vector<vector<string>> res;
        helper(curr , res , dp , 0 ,s );
        return res;

        
    }
};
int main(){

    string s = "aab";
    Solution obj;
    vector<vector<string>> ans = obj.partition(s);
    for(vector<string> i : ans){
        for(string j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}