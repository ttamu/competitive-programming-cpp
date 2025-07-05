#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        vector<long long> a;
        vector<long long> b;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        ranges::sort(A);
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                a.push_back(A[i]);
            } else {
                b.push_back(A[i]);
            }
        }

        if (a.empty() || b.empty()) {
            long long r1 = A[0];
            long long r2 = A[1];
            bool ok      = true;
            for (int i = 0; i < N - 1; i++) {
                if (A[i] * r2 != A[i + 1] * r1) {
                    ok = false;
                }
            }
            cout << (ok ? "Yes" : "No") << endl;

        } else {
            bool ok = false;

            for (int cn = 0; cn < 2; cn++) {
                int id1 = a.size() - 1;
                int id2 = 0;
                bool ng = false;
                vector<long long> B;
                for (int i = 0; i < N; i++) {
                    if (i % 2 == cn) {
                        if (id1 < 0) {
                            ng = true;
                            break;
                        }
                        B.push_back(a[id1]);
                        id1--;
                    } else {
                        if (id2 >= b.size()) {
                            ng = true;
                            break;
                        }
                        B.push_back(b[id2]);
                        id2++;
                    }
                }
                if (ng) {
                    continue;
                }

                bool flg     = true;
                long long r1 = B[0];
                long long r2 = B[1];
                for (int i = 0; i < N - 1; i++) {
                    if (B[i] * r2 != B[i + 1] * r1) {
                        flg = false;
                    }
                }
                if (flg) {
                    ok = true;
                }
            }

            cout << (ok ? "Yes" : "No") << endl;
        }
    }
}
