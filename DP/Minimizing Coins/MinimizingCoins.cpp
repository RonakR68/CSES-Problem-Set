#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// int solve(int i, int target, vector<int> &nums,  vector<vector<int>> &dp){
//     int n = nums.size();
//     if(target == 0) return 0;
//     if(target < 0 || i==n) return 1e8;
//     if(dp[i][target] != -1) return dp[i][target];
    
//     //cout<<i<<endl;
//     int t = 1e8, nt = 1e8;
//     if(nums[i] <= target){
//         t = 1 + solve(i, target-nums[i], nums, dp);
//     }
    
//     nt = solve(i+1, target, nums, dp);
//     return dp[i][target] = min(t,nt);
// }

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
    for(int target = 0; target <= x; target++)
        dp[n][target] = 1e8;
    for(int i=n-1; i>=0; i--){
        for(int target = 1; target <= x; target++){
            int t = 1e8, nt = 1e8;
            if(nums[i] <= target){
                t = 1 + dp[i][target-nums[i]];
            }
            
            nt = dp[i+1][target];
            dp[i][target] = min(t,nt);
        }
    }
    int ans = dp[0][x];
    cout << (ans == 1e8 ? -1 : ans) << endl;
    return 0;
}