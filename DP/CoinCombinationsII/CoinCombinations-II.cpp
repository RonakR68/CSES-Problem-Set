#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// int solve(int i, int x, vector<int> &v, vector<vector<int>> &dp){
//     int n = v.size();
//     if(x==0) return 1;
//     if(i==n || x<0) return 0;
//     if(dp[i][x]!=-1) return dp[i][x];
//     int ans = 0;
//     if(v[i]<=x){
//         ans = (ans+solve(i,x-v[i],v, dp))%mod;
//     }
    
//     ans = (ans+solve(i+1, x, v, dp))%mod;
//     return dp[i][x] = ans;
    
// }

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    vector<int> curr(x+1,0), next(x+1,0);
    curr[0] = 1;
    
    int k = x;
    for(int i=n-1; i>=0; i--){
        for(int x=1; x<=k; x++){
            int ans = 0;
            if(v[i]<=x){
                ans = (ans+curr[x-v[i]])%mod;
            }
            
            ans = (ans+next[x])%mod;
            curr[x] = ans;
        }
        next = curr;
    }
    
    cout<<curr[k]<<endl;;
    return 0;
}
