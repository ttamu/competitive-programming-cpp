#include <atcoder/maxflow>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), R(N), d;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> R[i];
        d.push_back(X[i] - R[i]);
        d.push_back(X[i] + R[i]);
    }
    ranges::sort(d);
    d.erase(ranges::unique(d).begin(), d.end());

    const int siz = N + d.size() + 2;
    const int S = 0, T = siz;
    atcoder::mf_graph<int> g(siz + 1);
    for (int i = 1; i <= N; i++) g.add_edge(S, i, 1);
    for (int i = 0; i < N; i++) {
        int id1 = ranges::lower_bound(d, X[i] + R[i]) - d.begin();
        int id2 = ranges::lower_bound(d, X[i] - R[i]) - d.begin();
        g.add_edge(i + 1, N + id1 + 1, 1);
        g.add_edge(i + 1, N + id2 + 1, 1);
    }
    for (int id = 1; id <= d.size(); id++) g.add_edge(N + id, T, 1);

    cout << g.flow(S, T) << endl;
}