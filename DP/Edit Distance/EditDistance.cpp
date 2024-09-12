#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
//     int n = s1.size(), m = s2.size();
//     if(i==n) return m-j;
//     if(j==m) return n-i;
//     if(dp[i][j] != -1) return dp[i][j];
//     if(s1[i]==s2[j]) return solve(i+1,j+1,s1,s2,dp);
//     int ins = 1 + solve(i,j+1,s1,s2,dp);
//     int del = 1 + solve(i+1,j,s1,s2,dp);
//     int rep = 1 + solve(i+1,j+1,s1,s2,dp);
//     return dp[i][j] = min(ins,min(rep,del));
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0; i<=n; i++) dp[i][m] = n-i;
    for(int j=0; j<=m; j++) dp[n][j] = m-j;
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i+1][j+1];
                continue;
            }
            dp[i][j] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
        }
    }
    cout<<dp[0][0]<<"\n";
    
    return 0;
}