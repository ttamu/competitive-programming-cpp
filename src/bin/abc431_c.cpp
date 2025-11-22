#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> head(N);
    multiset<int> body;
    for (int i = 0; i < N; i++) cin >> head[i];
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        body.insert(b);
    }
    ranges::sort(head);

    int cnt = 0;
    for (auto hi : head) {
        if (auto b_it = body.lower_bound(hi); hi <= *b_it) {
            cnt++;
            body.erase(b_it);
        }
    }
    cout << (cnt >= K ? "Yes" : "No") << endl;
}