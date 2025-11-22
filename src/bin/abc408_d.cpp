#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int m = 3;
constexpr int INF = 2e9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        vector<vector<int>> dp(N + 1, vector<int>(m, INF));
        dp[0][0] = 0;
        for (int i = 0; i < N; i++) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (S[i] == '1' ? 1 : 0));
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (S[i] == '0' ? 1 : 0));
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (S[i] == '0' ? 1 : 0));
            dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + (S[i] == '1' ? 1 : 0));
            dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + (S[i] == '1' ? 1 : 0));
        }

        cout << min({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    }
}
