#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int ans = 0;
    vector<bool> seen(N), finished(N);
    auto dfs = [&](auto &self, int u, int prev) -> void {
        seen[u] = true;
        for (int v : E[u]) {
            if (v == prev) continue;
            if (seen[v] && !finished[v]) ans++;
            if (!seen[v]) self(self, v, u);
        }
        finished[u] = true;
    };

    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            dfs(dfs, i, -1);
        }
    }
    cout << ans << endl;
}
