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
    set<vector<vector<bool>>> st;
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    auto dfs = [&](auto dfs, vector<vector<bool>> grid) -> void {
        st.insert(grid);

        ll res = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!grid[i][j]) {
                    res ^= A[i][j];
                }
            }
        }
        ans = max(ans, res);

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!grid[i][j]) {
                    if (!st.contains(grid)) dfs(dfs, grid);
                }

                if (i + 1 < H && !grid[i][j] && !grid[i + 1][j]) {
                    grid[i][j] = true;
                    grid[i + 1][j] = true;
                    if (!st.contains(grid)) dfs(dfs, grid);
                    grid[i][j] = false;
                    grid[i + 1][j] = false;
                }

                if (j + 1 < W && !grid[i][j] && !grid[i][j + 1]) {
                    grid[i][j] = true;
                    grid[i][j + 1] = true;
                    if (!st.contains(grid)) dfs(dfs, grid);
                    grid[i][j] = false;
                    grid[i][j + 1] = false;
                }
            }
        }
    };
    dfs(dfs, grid);

    cout << ans << endl;
}
