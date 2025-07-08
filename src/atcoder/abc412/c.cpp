#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> S(N);
        vector<int> s;
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            if (i != 0 && i != N - 1) {
                s.push_back(S[i]);
            }
        }
        ranges::sort(s);

        int now = S[0];
        int cnt = 1;
        int ans = -1;
        for (int i = 0; i < N; i++) {
            cnt++;
            if (now * 2 >= S.back()) {
                ans = cnt;
                break;
            }
            auto it = ranges::upper_bound(s, now * 2) - s.begin();
            it--;
            if (it >= 0) {
                now = s[it];
            }
        }

        cout << ans << endl;
    }
}
