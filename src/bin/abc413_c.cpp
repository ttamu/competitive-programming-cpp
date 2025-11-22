#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    deque<pair<long long, long long>> q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            long long c, x;
            cin >> c >> x;
            if (!q.empty() && q.back().first == x) {
                q.back().second += c;
            } else {
                q.emplace_back(x, c);
            }
        }
        if (op == 2) {
            long long k;
            cin >> k;
            long long sum = 0;
            while (!q.empty() && k > 0) {
                auto [x, cn] = q.front();
                q.pop_front();
                if (cn <= k) {
                    sum += cn * x;
                    k -= cn;
                    cn = 0;
                } else {
                    sum += k * x;
                    cn -= k;
                    k = 0;
                    q.emplace_front(x, cn);
                }
            }
            cout << sum << endl;
        }
    }
}
