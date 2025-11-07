#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int INF = 2e9;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    int sx = -1, sy = -1;
    int gx = -1, gy = -1;
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    vector dist(vector(H, vector(W, vector(2, -1))));
    q.emplace(sx, sy, 0);
    dist[sx][sy][0] = 0;
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (grid[nx][ny] == '#') continue;
            if (grid[nx][ny] == 'x' && cnt % 2 == 0) continue;
            if (grid[nx][ny] == 'o' && cnt % 2 == 1) continue;

            int ncn = cnt ^ (grid[nx][ny] == '?');
            if (dist[nx][ny][ncn] == -1) {
                dist[nx][ny][ncn] = dist[x][y][cnt] + 1;
                q.emplace(nx, ny, ncn);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 2; i++) {
        if (dist[gx][gy][i] == -1) continue;
        ans = min(ans, dist[gx][gy][i]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}