#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    ll ans = 0;
    vector<bool> vis(1 << (H * W), false);
    auto dfs = [&](auto dfs, int grid) -> void {
        vis[grid] = true;

        ll res = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!(grid & 1 << (i * W + j))) {
                    res ^= A[i][j];
                }
            }
        }
        ans = max(ans, res);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i + 1 < H && !(grid & 1 << (i * W + j)) &&
                    !(grid & 1 << ((i + 1) * W + j))) {
                    int next_grid = grid;
                    next_grid |= 1 << (i * W + j);
                    next_grid |= 1 << ((i + 1) * W + j);
                    if (!vis[next_grid]) dfs(dfs, next_grid);
                }

                if (j + 1 < W && !(grid & 1 << (i * W + j)) &&
                    !(grid & 1 << (i * W + j + 1))) {
                    int next_grid = grid;
                    next_grid |= 1 << (i * W + j);
                    next_grid |= 1 << (i * W + j + 1);
                    if (!vis[next_grid]) dfs(dfs, next_grid);
                }
            }
        }
    };
    dfs(dfs, 0);

    cout << ans << endl;
}
