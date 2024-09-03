#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp){
    //cout<<n<<endl;
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    string s = to_string(n);
    int ans = INT_MAX;
    for(char d: s){
        int digit = d-'0';
        //cout<<"digit: "<<digit<<endl;
        if(digit <= n && digit != 0){
            ans = min(ans, 1 + solve(n-digit,dp));
        }
    }
    return dp[n] =  ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<< solve(n,dp) << endl;
    
    return 0;
}
