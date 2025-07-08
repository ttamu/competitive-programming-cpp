#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 2e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> E(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        E[a][b] = true;
        E[b][a] = true;
    }

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);

    int ans = INF;
    do {
        for (int sp = 0; sp < p.size(); sp++) {
            auto edge = E;
            vector<int> g1(p.begin(), p.begin() + sp);
            vector<int> g2(p.begin() + sp, p.end());

            if ((!g1.empty() && g1.size() < 3) ||
                (!g2.empty() && g2.size() < 3)) {
                continue;
            }

            int cost = 0;
            for (auto g : {g1, g2}) {
                int siz = static_cast<int>(g.size());
                for (int i = 0; i < siz; i++) {
                    int u = g[i];
                    int prev_v = g[(i - 1 + siz) % siz];
                    int next_v = g[(i + 1) % siz];

                    if (!edge[u][next_v]) {
                        edge[u][next_v] = true;
                        edge[next_v][u] = true;
                        cost++;
                    }

                    for (int v = 0; v < N; v++) {
                        if (edge[u][v]) {
                            if (v != prev_v && v != next_v) {
                                edge[u][v] = false;
                                edge[v][u] = false;
                                cost++;
                            }
                        }
                    }
                }
            }

            ans = min(ans, cost);
        }
    } while (ranges::next_permutation(p).found);

    cout << ans << endl;
}
