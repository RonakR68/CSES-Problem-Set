#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string bfs(int x, int y, int ex, int ey, int n, int m, vector<vector<char>> &v){
    // cout << x << ' ' << y << '\n';
    vector<vector<int>> vis(n, vector<int>(m, 0));
    //vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m));
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    vector<int> dx = {-1,0,1,0}, dy = {0,1,0,-1};
    vector<char> dir = {'U','R','D','L'};
    while(!q.empty()){
        int cx, cy;
        cx = q.front().first, cy = q.front().second;
        q.pop();
        
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && v[nx][ny] != '#') {
                vis[nx][ny] = 1;
                direction[nx][ny] = dir[i];
                q.push({nx, ny});
                if(nx == ex && ny == ey){
                    string path = "";
                    cx = nx, cy = ny;
                   // cout << x << ' ' << y << '\n';
                    while(cx != x || cy != y){
                        
                        //cout << cx << ' ' << cy << '\n';
                        path += direction[cx][cy];
                        if(direction[cx][cy]=='U'){
                            cx = cx+1;
                        }
                        else if(direction[cx][cy]=='D'){
                            cx = cx-1;
                        }
                        else if(direction[cx][cy]=='L'){
                            cy = cy+1;
                        }
                        else if(direction[cx][cy]=='R'){
                            cy = cy-1;
                        }
                    }
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<direction[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    return "NO";

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    int sx,sy,ex,ey;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                sx = i;
                sy = j;
            }
            if(v[i][j]=='B'){
                ex = i;
                ey = j;
            }
        }
    }
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    string ans = bfs(sx,sy,ex,ey,n,m,v);
    if(ans != "NO"){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    else
        cout<<ans<<endl;

    return 0;
}
