#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int m , int n , int i , int j , vector<vector<int>> &memo){
        if(i > m || j > n){
            return 0;
        }
        if(i == m && j == n){
            return 1;
        }
        
        int count = 0 ;

        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        count+=helper(m , n , i+1 , j , memo);

        
        count+=helper(m , n , i , j+1 , memo);
        
        return memo[i][j] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m , vector<int> (n , -1));
        cout<<helper(m-1 , n-1 , 0 , 0 , memo);
    }
};

int main(){
    int m = 3;
    int n = 7;
    Solution obj;
    obj.uniquePaths(m , n);
    

}