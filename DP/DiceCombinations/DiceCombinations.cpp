#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int solve(int n, vector<int> &dp){
//     // cout<<n<<endl;
//     // cout<<dp[n]<<endl;
//     if(n == 0) return 1;
//     if(n <= 0) return 0;
//     int mod = 1e9+7;
    
//     if(dp[n] != -1) return dp[n];
//     int ans = 0;
//     for(int i=1; i <= min(6,n); i++){
//         ans = (ans + solve(n-i, dp)) % mod;
//     }
//     //cout<<"dp "<<dp[n]<<endl;
//     return dp[n] = ans;

// }


int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    int mod = 1e9+7;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(6, i); ++j) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout<< dp[n] << endl;
    return 0;
}