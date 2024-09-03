// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int i,  vector<vector<int>> &adj, vector<int> &vis){
    
//     vis[i]=1;
//     for(int node: adj[i]){
//         if(!vis[node]){
//             dfs(node,adj,vis);
//         }
//     }
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> adj(n+1);
//     for(int i=0; i<m; i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
    
//     vector<int> vis(n+1,0);
//     int cnt = 0;
//     vector<vector<int>> ans;
//     int prev = -1;
//     for(int i=1; i<=n; i++){
//         if(!vis[i]){
//             if(prev != -1){
//                 ans.push_back({prev,i});
//             }
//             prev = i;
//             //cout<<i<<endl;
//             dfs(i,adj,vis);
//             cnt++;
//         }
//     }
//     cout<<cnt-1<<endl;
//     for(auto it: ans){
//         cout<<it[0]<<" "<<it[1]<<endl;
//     }

   
//     return 0;
// }


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int> parent, sz;
    DSU(int n){
        parent.resize(n+1,0);
        sz.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        parent[node] = findUPar(parent[node]);
        return parent[node];
    }
    
    bool unionBySize(int u, int v){
        int paru = findUPar(u);
        int parv = findUPar(v);
        if(paru == parv) return false;
        if(sz[paru] < sz[parv]){
            parent[paru] = parv;
            sz[parv] += sz[paru];
        }
        else{
            parent[parv] = paru;
            sz[paru] += sz[parv];
        }
        return true;
    }
};



int main(){
    int n,m;
    cin>>n>>m;
    DSU ds(n);
    int cnt = 0;
    vector<vector<int>> ans;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        ds.unionBySize(u,v);
    }
    for(int i=2; i<=n; i++){
        if(ds.findUPar(1) != ds.findUPar(i)){
            cnt++;
            ans.push_back({1,i});
            ds.unionBySize(1,i);
        }
    }
    cout<<cnt<<endl;
    for(auto it: ans)
        cout<<it[0]<<" "<<it[1]<<endl;
    
    

   
    return 0;
}
