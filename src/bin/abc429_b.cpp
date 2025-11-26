#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int sum = 0;
    for (auto &ai : A) {
        cin >> ai;
        sum += ai;
    }
    for (auto ai : A) {
        if (sum - ai == M) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
