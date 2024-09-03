#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited, vector<int> &parent_node, int &cycle_start, int &cycle_end) {
    visited[node] = 1;
    for (int ne : adj[node]) {
        if (ne == parent) continue;
        if (visited[ne] == 0) {
            parent_node[ne] = node;
            if (dfs(ne, node, adj, visited, parent_node, cycle_start, cycle_end)) {
                return true;
            }
        } else {
            cycle_start = ne;
            cycle_end = node;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n + 1, 0), parent_node(n + 1, -1);
    int cycle_start = -1, cycle_end = -1;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0 && dfs(i, -1, adj, visited, parent_node, cycle_start, cycle_end)){
            break;
        }
    }

    if(cycle_start == -1){
        cout << "IMPOSSIBLE" << endl;
    } 
    else{
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for(int v = cycle_end; v != cycle_start; v = parent_node[v]){
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        cout << cycle.size() << endl;
        for(int v : cycle){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}