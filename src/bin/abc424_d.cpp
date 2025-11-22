#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

const int INF = 2e9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, W;
        cin >> H >> W;
        vector<string> grid(H);
        for (int i = 0; i < H; i++) cin >> grid[i];
        vector<int> state(H);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == '#') {
                    state[i] |= 1 << j;
                }
            }
        }

        vector<vector<int>> dp(H, vector<int>(1 << W, INF));
        // 初期化: 0行目をbitにできるか
        for (int bit = 0; bit < (1 << W); bit++) {
            if ((bit | state[0]) != state[0]) continue; // 黒→白のみ
            const int cost = __builtin_popcount(state[0] ^ bit);
            dp[0][bit] = cost;
        }

        for (int i = 0; i < H - 1; i++) {
            for (int prev = 0; prev < (1 << W); prev++) {
                for (int cur = 0; cur < (1 << W); cur++) {
                    if ((cur | state[i + 1]) != state[i + 1]) continue; // 黒→白のみ

                    // 2*2の黒ブロックができるか判定
                    bool ok = true;
                    for (int j = 0; j < W - 1; j++) {
                        if ((prev >> j & 3) == 3 && (cur >> j & 3) == 3) {
                            ok = false;
                        }
                    }
                    if (!ok) continue;

                    int cost = __builtin_popcount(state[i + 1] ^ cur);
                    dp[i + 1][cur] = min(dp[i + 1][cur], dp[i][prev] + cost);
                }
            }
        }

        int ans = INF;
        for (int bit = 0; bit < (1 << W); bit++) {
            ans = min(ans, dp[H - 1][bit]);
        }
        cout << ans << endl;
    }
}