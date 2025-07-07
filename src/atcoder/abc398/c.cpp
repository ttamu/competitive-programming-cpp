#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    int mx = -1;
    for (auto [val, cn] : cnt) {
        if (cn == 1) {
            mx = max(mx, val);
        }
    }
    for (int i = 0; i < N; i++) {
        if (mx == A[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
