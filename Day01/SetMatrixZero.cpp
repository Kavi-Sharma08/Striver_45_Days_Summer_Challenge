#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        set<pair<int,int>> st;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    st.insert({i , j});
                }
            }
        }

        for(auto it : st){
            int row = it.first;
            int col = it.second;

            //right

            for(int j =  col + 1   ; j < n ; j++){
                if(mat[row][j]!=0){
                    mat[row][j] = 0;

                }
            }

            //left 

            for(int j =  col - 1   ; j >= 0  ; j-- ){
                if(mat[row][j]!=0){
                    mat[row][j] = 0;

                }
            }

            // top

            for(int  i = row - 1  ; i >= 0 ; i--){
                if(mat[i][col] != 0){
                    mat[i][col] = 0;

                }
            }

            // bottom

            for(int  i = row + 1 ; i < m ; i++){
                if(mat[i][col]!=0){
                    mat[i][col] = 0;

                }
            }


            
        }
    }
};


int main(){
    vector<vector<int>> mat = {
        {1, 1 , 1},
        {1 , 0 , 1},
        {1 , 1 , 1},
    };
    Solution obj;
    obj.setZeroes(mat);

    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ;j < mat[i].size() ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }



}
           
// TC -> O(n*m) + O(m*n) * O(n+m)
// SC -> O(n+m)