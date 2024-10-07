#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long solve(int i, int j, vector<int> &nums, vector<vector<long long>> &dp){
    int n = nums.size();
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if((i+n-1-j)%2){
        //other turn
        return dp[i][j] = min(solve(i+1,j,nums,dp)-nums[i], solve(i,j-1,nums,dp)-nums[j]);  
    }
    else{
        //my return
        return dp[i][j] = max(solve(i+1,j,nums,dp)+nums[i], solve(i,j-1,nums,dp)+nums[j]);  
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int> nums(n);
    long long sum = 0;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        sum += nums[i];
    }
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
    long long score = solve(0,n-1,nums,dp);
    cout<<(sum+score)/2<<endl;
    

    return 0;
}