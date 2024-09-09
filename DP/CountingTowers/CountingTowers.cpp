#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    vector<vector<long long>> dp(1000002,vector<long long>(2,0));
    dp[1][0] = 1, dp[1][1] = 1;
    int mod = 1e9+7;
    for(int i=1; i<1000000; i++){
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i+1][0] = (dp[i+1][0] + 2*dp[i][0]) % mod;
        dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % mod;
        dp[i+1][0] = (dp[i+1][0] + dp[i][1]) % mod;
        dp[i+1][1] = (dp[i+1][1] + 4*dp[i][1]) % mod;
    }
    while(t--){
        int n;
        cin>>n;
        long long ans = (dp[n][0] + dp[n][1]) % mod;
        cout<<ans<<endl;
    }
    return 0;
}
