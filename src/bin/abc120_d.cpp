#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    ll cur = (ll)N * (N - 1) / 2;
    vector<ll> ans(M + 1);
    ans[M] = cur;
    atcoder::dsu uf(N);
    for (int i = M - 1; i >= 0; i--) {
        if (!uf.same(A[i], B[i])) {
            cur -= uf.size(A[i]) * uf.size(B[i]);
        }
        uf.merge(A[i], B[i]);
        ans[i] = cur;
    }

    for (int i = 1; i <= M; i++) {
        cout << ans[i] << endl;
    }
}