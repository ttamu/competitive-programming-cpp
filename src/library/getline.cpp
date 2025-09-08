#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

/* input
7000 4
Grass Slayer 2000,9999,10,120,120
Slow-Mowe,999,1,120,240
Eco-cut X2,5499,2,25,35
Mowepower,5499,3,25,35
 */

struct mower {
    string name;
    ll p, c, t, r;
};

int main() {
    ll l, m;
    cin >> l >> m;
    cin.ignore(); // 1行目の残り改行を捨てる

    vector<pair<ll, string>> ans;
    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line); // 名前に空白があるため1行まるごと読む

        int pos = line.find(',');
        string name = line.substr(0, pos);

        string rest = line.substr(pos + 1), tmp;
        stringstream ss(rest);
        vector<int> nums;
        while (getline(ss, tmp, ',')) {
            nums.push_back(stoi(tmp));
        }
        mower mo = {name, nums[0], nums[1], nums[2], nums[3]};

        if (10080LL * mo.c * mo.t / (mo.t + mo.r) >= l) {
            if (!ans.empty() && ans.back().first > mo.p) ans.clear();
            if (ans.empty() || ans.back().first == mo.p) ans.emplace_back(mo.p, mo.name);
        }
    }

    if (ans.empty()) {
        cout << "no such mower" << endl;
        return 0;
    }
    for (auto &[p, name] : ans) {
        cout << name << endl;
    }
}