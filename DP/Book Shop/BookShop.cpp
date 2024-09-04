#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int solve(int i, int x, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp){
//     int n = price.size();
//     if(x <= 0 || i==n) return 0;
    
//     if(dp[i][x] != -1) return dp[i][x];
    
//     int t = 0, nt = 0;
    
//     if(price[i] <= x)
//         t = pages[i] + solve(i+1, x-price[i], price, pages, dp);
    
//     nt = solve(i+1, x, price, pages, dp);
    
//     return dp[i][x] = max(t,nt);
    
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin>>n>>x;
    
    vector<int> price(n+1), pages(n+1);
    for(int i=0; i<n; i++)
        cin>>price[i];
    for(int i=0; i<n; i++)
        cin>>pages[i];
        
    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
    
    int k = x;
    for(int i=n-1; i>=0; i--){
        for(int x=0; x<=k; x++){
             int t = 0, nt = 0;
    
            if(price[i] <= x)
                t = pages[i] + dp[i+1][x-price[i]];
            
            nt = dp[i+1][x];
            dp[i][x] = max(t,nt);
        }
    }
    
    cout<< dp[0][x] << "\n";

    return 0;
}