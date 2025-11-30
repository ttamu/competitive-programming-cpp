#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, H;
        cin >> N >> H;
        vector<int> T(N), L(N), U(N);
        for (int i = 0; i < N; i++) cin >> T[i] >> L[i] >> U[i];

        bool ok = true;
        int lo = H, hi = H, prev = 0;
        for (int i = 0; i < N; i++) {
            int dt = T[i] - prev;
            lo -= dt, hi += dt;
            lo = max(lo, L[i]);
            hi = min(hi, U[i]);
            if (hi < lo) ok = false;
            prev = T[i];
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}
