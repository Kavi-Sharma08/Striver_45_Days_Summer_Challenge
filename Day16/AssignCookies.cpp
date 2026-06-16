#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());

        sort(s.begin() , s.end());
        
        int i = 0 , j = 0;
        int count = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};

int main(){
    vector<int> g = {10,9,8,7};
    vector<int> s= {5,6,7,8};
    Solution obj;
    cout<<obj.findContentChildren(g ,s);
}