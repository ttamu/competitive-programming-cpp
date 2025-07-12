#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ok(ll X, ll Y, ll Z) {
    if (Y % 2 == 0) {
        if (X < Z) return false;
        if (Y > 2 * X) return false;
    } else {
        if (Z < 1) return false;
        if (X < Z) return false;
        if (Y + 1 > 2 * X) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll X, Y, Z;
        cin >> X >> Y >> Z;
        cout << (ok(X, Y, Z) ? "Yes" : "No") << endl;
    }
}
