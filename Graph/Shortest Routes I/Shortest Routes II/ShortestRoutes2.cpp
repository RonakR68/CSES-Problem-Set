#include<bits/stdc++.h>
using namespace std;
const long long INF = LONG_MAX;

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        long long wt;
        cin >> u >> v >> wt;
        dist[u][v] = min(dist[u][v], wt);
        dist[v][u] = min(dist[v][u], wt);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        long long ans = dist[a][b] == LONG_MAX ? -1 : dist[a][b];
        cout<<ans<<"\n";
    }
    return 0;
}
