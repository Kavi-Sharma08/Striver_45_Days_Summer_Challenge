#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> row1 = {1};
        vector<int> row2 = {1 , 1};

        vector<vector<int>> ans;
        ans.push_back(row1);
        if(numRows == 1) return ans;
        ans.push_back(row2);
        if(numRows == 2) return ans;
        
        for(int i = 2 ; i < numRows ; i++){
            vector<int> pascalRow;
            vector<int> previousRow(ans[ans.size()-1]);
            for(int j = 0 ; j <= i ; j++){
                if( j == 0 || j == i){
                    pascalRow.push_back(1);
                }
                else{
                    int sum = previousRow[j] + previousRow[j-1];
                    pascalRow.push_back(sum);
                }

            }
            ans.push_back(pascalRow);
        }
        return ans;
    }
};

int main(){
    // int numRows;
    // cout<<"Enter no of rows : ";
    // cin>>numRows;
    Solution obj;
    vector<vector<int>> vec = obj.generate(5);
    for(int i = 0 ; i < vec.size() ; i++){
        for(int j = 0 ; j < vec[i].size() ; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    

}

// TC --> O((n-2) * (n+1))  --> O(n^2)
// SC --> O(n) + O(n) + O(n*n) --> O(n^2)