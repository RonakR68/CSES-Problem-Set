#include <iostream>
#include <bits/stdc++.h>
using namespace std;


long long solve(int i, int m, long long prev, vector<int> &v, vector<vector<long long>> &dp){
    int mod = 1e9+7;
    if(i == v.size()) return 1;
    if(dp[i][prev] != -1) return dp[i][prev];
    long long ans = 0;
    if(v[i] != 0){
        if(abs(v[i] - prev) < 2 || i == 0){
            ans = solve(i + 1, m, v[i], v, dp);
        }
    }
    else{
        long long mini = prev == 1 ? 1 : prev - 1;
        long long maxi = prev == m ? m : prev + 1;
        for(long long j = mini; j <= maxi; j++){
            ans = (ans + solve(i + 1, m, j, v, dp)) % mod;
        }
    }
    dp[i][prev] = ans;
    return dp[i][prev];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int mod = 1e9+7;
    vector<vector<long long>> dp(n, vector<long long>(m + 2, -1));
    long long ans = 0;
    if(v[0] == 0){
        for (int i = 1; i <= m; i++){
            ans = (ans + solve(1, m, i, v, dp)) % mod;
        }
    }
    else{
        ans = solve(1, m, v[0], v, dp);
    }
    cout << ans << '\n';

    return 0;
}