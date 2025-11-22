#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<set<int>> rows(H + 1), cols(W + 1);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        rows[x].insert(y);
        cols[y].insert(x);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            for (auto y : rows[x]) {
                cols[y].erase(x);
            }
            cout << rows[x].size() << endl;
            rows[x].clear();
        }
        if (type == 2) {
            int y;
            cin >> y;
            for (auto x : cols[y]) {
                rows[x].erase(y);
            }
            cout << cols[y].size() << endl;
            cols[y].clear();
        }
    }
}
