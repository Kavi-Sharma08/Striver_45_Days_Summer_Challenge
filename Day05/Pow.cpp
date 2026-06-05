#include<bits/stdc++.h>
using namespace std;

// Tc --> O(log(n))
// Sc --> O(1)
class Solution {
public:
    double pow(double x, long long n){
        if(n == 1) return x;

        double ans = pow(x , n/2);

        if(n % 2 == 0){
            ans = ans*ans;
        }
        else {
            ans = ans*ans*x;
        }
        return ans;


    }
    double myPow(double x, int n) {
        long long q = n;
        if(n == 0) return 1;
        if(n==1) return x;

        if(n < 0){
            q = -q;
            x = 1/x;
        }
        return pow(x , n);
    }
};

int main(){
    double x =  1;
    int n = -2147483648;
    Solution obj;
    cout<<obj.myPow(x , n);
}