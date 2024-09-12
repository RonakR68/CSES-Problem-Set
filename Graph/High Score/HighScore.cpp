#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, unordered_set<int> &s){
    vis[node] = 1;
    if(s.find(node) != s.end()) return true;
    for(int ne: adj[node]){
        if(!vis[ne])
            if(dfs(ne, vis, adj, s)) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> edges;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        long long wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
        adj[v].push_back(u);
    }
    
    vector<long long> dist(n+1, LLONG_MIN);
    dist[1] = 0;
    for(int i=1; i<=n-1; i++){
        for(auto it: edges){
            int u = it[0], v = it[1];
            long long wt = it[2];
            if(dist[u] != LLONG_MIN && dist[u] + wt > dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
   
    unordered_set<int> nodes;
    for(auto it: edges){
            int u = it[0], v = it[1];
            long long wt = it[2];
            if(dist[u] != LLONG_MIN && dist[u] + wt > dist[v]){
               nodes.insert(v);
            }
            
    }
    vector<int> vis(n+1,0);
    long long ans = dfs(n,vis,adj,nodes) ? -1 : dist[n];
    cout<<ans<<"\n";
    
    return 0;
}