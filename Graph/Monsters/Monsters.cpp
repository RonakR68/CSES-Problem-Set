#include<bits/stdc++.h>
using namespace std;

void bfs(queue<pair<int, int>> &q, vector<vector<int>> &dist, vector<string> &grid, int n, int m, int dx[], int dy[]) {
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

string tracePath(int x, int y, vector<vector<pair<int, int>>> &parent, vector<string> &grid, int dx[], int dy[], char dir[]) {
    string path;
    while(grid[x][y] != 'A'){
        auto [px, py] = parent[x][y];
        for(int i = 0; i < 4; i++) if(px + dx[i] == x && py + dy[i] == y) path += dir[i];
        x = px; y = py;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> distPlayer(n, vector<int>(m, -1)), distMonster(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};
    queue<pair<int, int>> qPlayer, qMonsters;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                qPlayer.push({i, j});
                distPlayer[i][j] = 0;
            } else if(grid[i][j] == 'M') {
                qMonsters.push({i, j});
                distMonster[i][j] = 0;
            }
        }
    }

    bfs(qMonsters, distMonster, grid, n, m, dx, dy);
    
    while(!qPlayer.empty()) {
        auto [x, y] = qPlayer.front(); qPlayer.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && distPlayer[nx][ny] == -1) {
                distPlayer[nx][ny] = distPlayer[x][y] + 1;
                parent[nx][ny] = {x, y};
                qPlayer.push({nx, ny});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && distPlayer[i][j] != -1 &&
               (distMonster[i][j] == -1 || distPlayer[i][j] < distMonster[i][j])) {
                cout << "YES" << endl;
                string path = tracePath(i, j, parent, grid, dx, dy, dir);
                cout << path.size() << endl;
                cout << path << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
