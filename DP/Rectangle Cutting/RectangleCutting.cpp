#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// int solve(int a, int b, vector<vector<int>> &dp){
//     if(a == b) return  0;
//     if(a < 0 || b < 0) return 1e8;
//     if(dp[a][b] != -1) return dp[a][b];
//     int ans = 1e8;
//     for(int i=1; i<a; i++){
//         ans = min(ans, 1 + solve(a-i,b,dp) + solve(i,b,dp));
//     }
//     for(int i=1; i<b; i++){
//         ans = min(ans, 1 + solve(a,b-i,dp) + solve(a,i,dp));
//     }
//     return dp[a][b] = ans;
        
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j) continue;
            int ans = 1e8;
            for(int k=1; k<i; k++){
                ans = min(ans, 1 + dp[i-k][j] + dp[k][j]);
            }
            for(int k=1; k<j; k++){
                ans = min(ans, 1 + dp[i][j-k] + dp[i][k]);
            }
            dp[i][j] = ans;
        }
    }
    
    int ans = dp[a][b];
    cout<<ans<<"\n";
    return 0;
}