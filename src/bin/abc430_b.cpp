#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    set<vector<string>> st;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<string> sub_grid(M);
            if (i + M > N || j + M > N) continue;
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    sub_grid[x].push_back(grid[i + x][j + y]);
                }
            }
            st.insert(sub_grid);
        }
    }

    cout << st.size() << endl;
}
