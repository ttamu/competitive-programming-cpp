#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;

int main() {
    string X, Y;
    cin >> X >> Y;
    map<string,int> conv {
            {"Ocelot",1},
            {"Serval",2},
            {"Lynx",3}
    };
    const int cx = conv[X];
    const int cy = conv[Y];
    cout << (cx >= cy ? "Yes" : "No") << endl;
}