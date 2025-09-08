#include <bits/stdc++.h>
using namespace std;

long long sqrtll(long long x) {
    assert(x >= 0);
    long long rev = sqrt(x);
    while (rev * rev > x) --rev;
    while ((rev + 1) * (rev + 1) <= x) ++rev;
    return rev;
}

int main() {
    cout << sqrtll(10) << endl;
    cout << sqrtll(25) << endl;
}