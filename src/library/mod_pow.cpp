#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long a, long long n, long long _mod) {
    long long ret = 1;
    while (n > 0) {
        if (n % 2 == 1) ret = ret * a % _mod;
        a = a * a % _mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    cout << mod_pow(2, 3, 1e9 + 7) << endl;
}