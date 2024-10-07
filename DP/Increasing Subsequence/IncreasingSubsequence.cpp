#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> lis;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if(it == lis.end()){
            lis.push_back(nums[i]);
        } 
        else{
            *it = nums[i];
        }
    }
    cout << lis.size() << "\n";
    return 0;
}
