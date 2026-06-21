#include<bits/stdc++.h>
using namespace std;
class Solution {
public:   
    bool isSafe(vector<vector<int>> &arr , int i , int j , int n , vector<vector<int>> &visited){
        if(i < n && j < n && visited[i][j] == 1 && i >= 0 && j >=0 && arr[i][j] == 1){
            return true;
        }
        return false;

    }
    void helper(vector<vector<int>> &arr , int i , int j , vector<string> &dp , int n , string s ,vector<vector<int>> &visited){
        if(i == n-1 && j == n-1){
            cout<<s<<endl;
            dp.push_back(s);
            return;
        }

        visited[i][j] = 0;
        //down
        if(isSafe(arr , i+1 , j , n , visited)){
            helper(arr , i+1 , j , dp , n , s+="D" , visited );
        }
        //right
        if(isSafe(arr , i , j+1 , n , visited)){
            helper(arr , i , j+1 , dp , n , s+="R" , visited );
        }
        
        //up
        if(isSafe(arr , i-1 , j , n ,  visited)){
            helper(arr , i-1 , j , dp , n , s+="U" , visited );
        }
        // left

        if(isSafe(arr , i , j-1 , n ,  visited)){
            helper(arr , i , j-1 , dp , n , s+="L" , visited );
        }
        
        visited[i][j]=1;
        
        
        
    }
    vector<string> maze(vector<vector<int>> &arr , int n){
        vector<string> dp;
        vector<vector<int>> visited(n , vector<int>(n , 1));
        helper(arr , 0 , 0 , dp , n , "" , visited);
        return dp;
    }
};
int main(){
    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    Solution obj;
    vector<string> ans = obj.maze(arr , n);
    for(string i : ans){
        cout<<i<<" ";
    }


}