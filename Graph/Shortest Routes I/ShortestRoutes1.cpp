#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<long long> dist(n+1,LONG_MAX);
    dist[1] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        
        for(auto ne: adj[u]){
            int v = ne.first;
            int wt = ne.second;
            //cout<<u<<" "<<d<<" "<<v<<" "<<wt<<endl;
            if(d+wt < dist[v]){
                dist[v] = d+wt;
                pq.push({dist[v], v});
            }
        }
            
    }
    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";
    return 0;
}
