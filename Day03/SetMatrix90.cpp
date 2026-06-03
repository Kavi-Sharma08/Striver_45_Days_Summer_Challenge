#include<bits/stdc++.h>
using namespace std;

// TC 

// 1) To Transpose the matrix  --> n*(n-1)/2
// 2) To Reverse the array --> n*(n/2) --> swap need n/2 iteration
// In terms of Big O --> O(n*(n-1)/2) + O(n*(n/2)) --> O(n^2) + O(n^2) --> O(n^2)

// SC --> O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(vector<int> &arr : matrix){
            reverse(arr.begin() , arr.end());
        }
    }
};

int main(){
    vector<vector<int>> arr = {
        {1 , 2 , 3},
        {4 , 5 , 6},
        {7 , 8, 9},
    };
    Solution obj;
    obj.rotate(arr);
    for(vector<int> i : arr){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

}