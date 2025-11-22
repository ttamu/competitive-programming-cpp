#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ranges::sort(A);
    A.erase(ranges::unique(A).begin(), A.end());

    cout << A.size() << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
