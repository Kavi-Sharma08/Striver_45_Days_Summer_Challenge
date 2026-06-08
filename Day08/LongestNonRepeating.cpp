#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int len = str.length();
        int maxLength = 0;
        int l = 0;
        int r = 0;
        unordered_map<char, int> mpp;

        while (r < len)
        {
            if (mpp.find(str[r]) == mpp.end() || mpp[str[r]] < l)
            {
            
                maxLength = max(maxLength, r - l + 1);
                mpp[str[r]] = r; 
                r++;
            }
            else
            {
            
                int repeatingCharIndex = mpp[str[r]];
                
                l = repeatingCharIndex + 1; 
                mpp[str[r]] = r;            
                r++;
            }
        }
        return maxLength;
        
        
    }
};
int main(){
    Solution obj;
    cout<<obj.lengthOfLongestSubstring("abcabcbb");

}