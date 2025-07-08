#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 2e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> imos(N + 2, 0);
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        imos[L]++;
        imos[R + 1]--;
    }

    int ans = INF;
    for (int i = 1; i <= N; i++) {
        imos[i] += imos[i - 1];
        ans = min(ans, imos[i]);
    }
    cout << ans << endl;
}
