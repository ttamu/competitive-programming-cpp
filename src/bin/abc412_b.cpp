#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;

    bool ok = true;
    for (int i = 0; i < S.size(); i++) {
        if (i > 0 && isupper(S[i])) {
            bool flg = false;
            for (char j : T) {
                if (j == S[i - 1]) {
                    flg = true;
                }
            }
            if (!flg) {
                ok = false;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
