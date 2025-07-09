#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> deg(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        deg[a[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    ll ans = 0;
    vector<int> siz(N, 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += siz[u];
        siz[a[u]] += siz[u];
        deg[a[u]]--;
        if (deg[a[u]] == 0) {
            q.push(a[u]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (deg[i] == 1) {
            int cycle_size = 0;
            int component_size = 0;
            int u = i;
            while (deg[u] == 1) {
                component_size += siz[u];
                cycle_size++;
                deg[u]--;
                u = a[u];
            }
            ans += static_cast<ll>(cycle_size) * component_size;
        }
    }

    cout << ans << endl;
}
