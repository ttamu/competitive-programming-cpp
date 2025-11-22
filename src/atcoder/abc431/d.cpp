#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 2e18;
const int MAX_WEIGHT = 500 * 500;

int main() {
    int N;
    cin >> N;
    ll sum_w = 0;
    vector<ll> W(N), H(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> H[i] >> B[i];
        sum_w += W[i];
    }

    vector<ll> dp(MAX_WEIGHT + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        auto ndp = dp;
        for (int w = 0; w <= MAX_WEIGHT; w++) {
            if (w + W[i] <= MAX_WEIGHT) {
                ndp[w + W[i]] = max(ndp[w + W[i]], dp[w] + H[i]);
            }
            ndp[w] = max(ndp[w], dp[w] + B[i]);
        }
        dp = ndp;
    }

    ll ans = -INF;
    for (int w = 0; w <= MAX_WEIGHT; w++) {
        int body_weight = sum_w - w;
        if (body_weight >= w) ans = max(ans, dp[w]);
    }
    cout << ans << endl;
}
