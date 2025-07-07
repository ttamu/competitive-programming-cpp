#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> T(N + 1, 0);

    bool ok = true;
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
        if (T[i] - T[i - 1] > S) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
