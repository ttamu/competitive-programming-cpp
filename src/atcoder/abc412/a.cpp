#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] < B[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
