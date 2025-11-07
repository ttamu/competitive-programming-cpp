#include <bits/stdc++.h>
#include <atcoder/dsu>
#define debug(x) cerr << #x << ": " << x << endl
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> cnt(N);
    vector<bool> black(N, false);
    atcoder::dsu uf(N);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v, u--, v--;
            if (uf.same(u, v)) continue;

            int cn = cnt[uf.leader(u)] + cnt[uf.leader(v)];
            cnt[uf.leader(u)] = 0;
            cnt[uf.leader(v)] = 0;

            uf.merge(u, v);
            cnt[uf.leader(u)] = cn;
        }
        if (type == 2) {
            int v;
            cin >> v, v--;
            if (black[v]) {
                cnt[uf.leader(v)]--;
                black[v] = false;
            } else {
                cnt[uf.leader(v)]++;
                black[v] = true;
            }
        }
        if (type == 3) {
            int v;
            cin >> v, v--;
            cout << (cnt[uf.leader(v)] >= 1 ? "Yes" : "No") << endl;
        }
    }
}