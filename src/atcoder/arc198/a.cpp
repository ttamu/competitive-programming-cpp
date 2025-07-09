#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }

    cout << N / 2 << endl;
    for (int i = 2; i <= N; i += 2) {
        cout << i << " ";
    }
    cout << endl;
}