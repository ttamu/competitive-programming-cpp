#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }

    ll ans = 0;
    for (auto &cn : mp | views::values) {
        if (cn >= 2) ans += (ll)cn * (cn - 1) / 2 * (N - cn);
    }
    cout << ans << endl;
}