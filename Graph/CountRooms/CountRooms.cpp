#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, int n, int m, vector<vector<char>> &v){
    vector<int> dx = {-1,0,1,0}, dy = {0,1,0,-1};
    queue<pair<int,int>> q;
    q.push({i,j});
    v[i][j]='#';

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int k=0; k<dx.size(); k++){
            int nx = x+dx[k], ny = y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]!='#'){
                q.push({nx,ny});
                v[nx][ny] = '#';
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]!='#'){
                ans++;
                bfs(i,j,n,m,v);
            }
        }
    }
    cout<<ans<<endl;

   
    return 0;
}
