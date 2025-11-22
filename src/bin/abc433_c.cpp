#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    auto compression = [&]() -> vector<pair<int, int>> {
        vector<pair<int, int>> ret;
        for (int l = 0; l < S.size(); l++) {
            int r = l;
            while (r + 1 < S.size() && S[l] == S[r + 1]) r++;
            ret.emplace_back(S[l] - '0', r - l + 1);
            l = r;
        }
        return ret;
    };

    int ans = 0;
    auto comp = compression();
    for (int i = 0; i < comp.size() - 1; i++) {
        if (comp[i].first + 1 == comp[i + 1].first) {
            ans += min(comp[i].second, comp[i + 1].second);
        }
    }
    cout << ans << endl;
}