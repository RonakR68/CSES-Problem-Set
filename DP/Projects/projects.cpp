#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int i, int n, vector<vector<int>> &v, vector<long long> &dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int next = -1;
    int low = i + 1, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(v[mid][0] > v[i][1]){
            next = mid;
            high = mid - 1;
        } 
        else{
            low = mid + 1;
        }
    }

    long long t = v[i][2];
    if(next != -1){
       t += solve(next, n, v, dp);
    }
    long long nt = solve(i + 1, n, v, dp);
    return dp[i] = max(t, nt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        vector<int> temp(3);
        cin>>temp[0]>>temp[1]>>temp[2];
        v[i] = temp;
    }
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0]<b[0];
    });
    vector<long long> dp(n,-1);
    long long ans = solve(0, n, v, dp);
    cout<<ans<<"\n";
    return 0;
}
