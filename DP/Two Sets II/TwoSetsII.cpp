
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int solve(int i, int n, int target, vector<vector<int>> &dp){
//     int mod = 1e9+7;
//     if(i>n || target < 0) return 0;
//     if(target == 0) return 1;
//     if(dp[i][target] != -1) return dp[i][target];
//     int ans = 0;
//     if(i <= target)
//         ans =  (ans + solve(i+1, n, target-i, dp))%mod;
//     ans = (ans+solve(i+1,n,target,dp))%mod;
//     return dp[i][target] = ans;
    
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mod = 1e9+7;
    int n;
    cin >> n;
    int t = n*(n+1)/2;
    if(t == 0 || t%2){
        cout<<0<<endl;
        return 0;
    }
    t /= 2;
    vector<vector<int>> dp(n+2,vector<int>(t+1,0));
    for(int i=1; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=n; i>=1; i--){
        for(int target = 1; target <= t; target++){
            int ans = 0;
            if(i <= target)
                ans =  (ans + dp[i+1][target-i])%mod;
            ans = (ans + dp[i+1][target])%mod;
            dp[i][target] = ans;
        }
    }
    cout<<dp[1][t]<<endl;

    return 0;
}