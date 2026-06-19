#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(vector<vector<char>> &board , int i , int j , int n){
        //vertically
        for(int row = 0 ; row < n ; row++ ){
            if(board[row][j] == 'Q'){
                return false;
            }
            
        }
        //horizontally
        for(int col = 0 ; col < n  ; col++ ){
            if(board[i][col] == 'Q'){
                return false;
            }
            
        }
        //diagonal top left
        for(int row = i , col = j ; row >=0 && col >= 0  ; col-- , row-- ){
            if(board[row][col] == 'Q'){
                return false;
            }
            
        }
        //diagonal top right
        for(int row = i , col = j  ; row >= 0 && col < n  ; col++ , row-- ){
            

            if(board[row][col] == 'Q'){
                return false;
            
            }
        }

        return true;


    }
    void helper(vector<vector<char>> &board , vector<vector<string>> &ans , int ind , int n){
        if(ind >= n){
            vector<string> ans2;
            for(int i = 0 ; i < n ; i++){
                string s = "";
                for(int j = 0 ; j < n ; j++){
                    s = s + board[i][j];
                }
                ans2.push_back(s);
            }
            ans.push_back(ans2);
            return;
        }
        for(int j = 0 ; j < n ; j++){
            if(isValid(board , ind  , j , n)){
                board[ind][j] = 'Q';
                helper(board , ans ,  ind + 1 , n);
                board[ind][j] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n , vector<char>(n , '.'));
        vector<vector<string>> ans;
        helper(board , ans, 0 , n);
        return ans;
    }
};
int main(){

    int n = 4;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}