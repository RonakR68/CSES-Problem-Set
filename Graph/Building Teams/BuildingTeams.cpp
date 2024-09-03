#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int team, vector<vector<int>> &adj, vector<int> &teams){
    teams[node] = team;
    for(int ne: adj[node]){
        if(teams[ne]==-1){
            if(!dfs(ne, 1-team, adj, teams)) return false;
        }
        else if(teams[ne]==teams[node]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    vector<int> teams(n+1,-1);
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(teams[i]==-1){
            if(!dfs(i,0,adj,teams)){
                //cout<<i<<endl;
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout<<teams[i]+1<<" ";
    }
    
    return 0;
}
