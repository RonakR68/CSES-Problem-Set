#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int i, int sum, vector<int> &nums, set<int> &s, vector<vector<int>> &dp){
    //cout<<i<<" "<<sum<<"\n";
    int n = nums.size();
    if(i==n){
        if(sum > 0) s.insert(sum);
        return;
    }
    
    if(dp[i][sum]) return;
    
    solve(i+1,sum+nums[i],nums,s,dp);
    solve(i+1,sum,nums,s,dp);
    dp[i][sum] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        sum += nums[i];
    }
        
    set<int> s;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    solve(0,0,nums,s,dp);
    cout<<s.size()<<"\n";
    for(int num:s)
        cout<<num<<" ";
    return 0;
}