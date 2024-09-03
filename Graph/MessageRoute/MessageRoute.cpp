#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n+1,-1);
    parent[1] = 1;
    queue<pair<int,int>> q; //{node,par}
    q.push({1,1});
    vis[1] = 1;
    int flag = 1;
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(int ne: adj[node]){
            if(!vis[ne]){
                if(parent[ne]==-1) parent[ne] = node;
                vis[ne]=1;
                q.push({ne,node});
                if(ne == n){
                    vector<int> path;
                    int u = n;
                    while(parent[u]!=u){
                        path.push_back(u);
                        u = parent[u];
                    }
                    path.push_back(u);
                    reverse(path.begin(),path.end());
                    flag = 0;
                    cout<<path.size()<<endl;
                    for(int node:path)
                        cout<<node<<" ";
                }
            }
        }
        
    }
    if(flag)
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
