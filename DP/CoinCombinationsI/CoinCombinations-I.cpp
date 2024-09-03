#include <iostream>
#include <bits/stdc++.h>
using namespace std;




// int solve(int x, vector<int> &v, vector<int> &dp){
//     int n = v.size();
//     if(x==0) return 1;
    
//     if(dp[x]!=-1) return dp[x];
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         if(v[i]<=x){
//             ans = (ans+solve(x-v[i],v,dp))%mod;
//         }
//     }
    
//     return dp[x] = ans;
    
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int mod = 1e9+7;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<int> dp(k+1,0);
    dp[0] = 1;
    for(int x=1; x<=k; x++){
        for(int i=0; i<n; i++){
            if(v[i]>x) break;
            dp[x] = (dp[x]+dp[x-v[i]])%mod;
        }
    }
    
    cout<<dp[k]<<endl;
    return 0;
}
