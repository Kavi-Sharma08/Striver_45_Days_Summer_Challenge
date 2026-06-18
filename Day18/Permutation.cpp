#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(string &s , int ind , vector<string> &ans){
        if(ind >= s.size()){
            ans.push_back(s);
            return;
        }
        for(int i = ind ; i  < s.size() ; i++){
            swap(s[ind] , s[i]);
            helper(s , ind + 1 , ans);
            swap(s[ind] , s[i]);
        }
    }
    string getPermutation(int n ,int k) {
        if(n==1) return "1";
        string s = "";
        for(int i = 1 ; i <=n ; i++){
            s = s + char(i + '0');
        }
        vector<string> ans;
        helper(s , 0 , ans);
        sort(ans.begin() , ans.end());
        return ans[k-1];
    }
};

int main(){

   int n = 3;
   int k = 1;
   Solution obj;
   string s = obj.getPermutation(n , k); 
   cout<<s;
   


}