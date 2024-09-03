#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int solve(int i, int j, int n, vector<vector<char>> &grid, vector<vector<int>> &dp){
//     if(i==n-1 && j==n-1) return 1;
//     if(grid[i][j]=='*') return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int mod = 1e9+7;
//     int down = 0, right = 0;
//     if(i<n-1)
//         down = solve(i+1,j,n,grid,dp)%mod;
//     if(j<n-1)
//         right = solve(i,j+1,n,grid,dp)%mod;
//     return dp[i][j] = (down+right)%mod;
    
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
           grid[i][j] = s[j];
        }
    }
    //  for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //       cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[n-1][n-1] = 1;
    int mod = 1e9+7;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int down = 0, right = 0;
            if(grid[i][j]=='*'){
                dp[i][j]=0;
                continue;
            }
            if(i<n-1)
                down = dp[i+1][j]%mod;
            if(j<n-1)
                right = dp[i][j+1]%mod;
            dp[i][j] = (dp[i][j]+down+right)%mod;
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
