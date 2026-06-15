#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeet(vector<int> &start , vector<int> &end){
        vector<int> ans;
        vector<pair<int, pair<int, int>>> vp;
        for(int i = 0 ; i < start.size() ; i++){
            vp.push_back( {end[i] , {start[i] , i }});
        }
        sort(vp.begin() , vp.end());
        int count = 1;
        int endTime = vp.begin()->first;
        for(auto it = vp.begin() + 1; it != vp.end(); it++){
            int startTime = it->second.first;
            if(startTime > endTime){
                count++;
                endTime = it->first;
            }

        }
        return count;
        
    }
};

int main(){
    vector<int> start = {1,5};
    vector<int> end = {7,8};
    Solution obj;
    cout<<obj.maxMeet(start , end);
    
}