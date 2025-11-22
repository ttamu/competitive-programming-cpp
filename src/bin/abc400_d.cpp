#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 2e9;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--, B--, C--, D--;

    deque<pair<int, int>> dq;
    vector dist(H, vector(W, INF));
    dq.emplace_front(A, B);
    dist[A][B] = 0;
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (grid[nx][ny] == '.') {
                if (dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y];
                    dq.emplace_front(nx, ny);
                }
            }
            if (grid[nx][ny] == '#') {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.emplace_back(nx, ny);
                }
            }

            int nnx = nx + dx[dir];
            int nny = ny + dy[dir];
            if (nnx < 0 || nnx >= H || nny < 0 || nny >= W) continue;
            if (grid[nnx][nny] == '#') {
                if (dist[nnx][nny] > dist[x][y] + 1) {
                    dist[nnx][nny] = dist[x][y] + 1;
                    dq.emplace_back(nnx, nny);
                }
            }
        }
    }

    cout << dist[C][D] << endl;
}