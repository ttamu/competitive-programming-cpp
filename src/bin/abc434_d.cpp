#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SIZ = 2000;

int main() {
    int N;
    cin >> N;
    vector<int> U(N), D(N), L(N), R(N);
    vector<vector<int>> pref1(SIZ + 2, vector<int>(SIZ + 2, 0));
    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        pref1[U[i]][L[i]]++;
        pref1[U[i]][R[i] + 1]--;
        pref1[D[i] + 1][L[i]]--;
        pref1[D[i] + 1][R[i] + 1]++;
    }

    for (int j = 1; j <= SIZ; j++)
        for (int i = 1; i <= SIZ; i++) pref1[i][j] += pref1[i - 1][j];
    for (int i = 1; i <= SIZ; i++)
        for (int j = 1; j <= SIZ; j++) pref1[i][j] += pref1[i][j - 1];

    int sum = 0;
    vector<vector<int>> pref2(SIZ + 2, vector<int>(SIZ + 2, 0));
    for (int j = 1; j <= SIZ; j++) {
        for (int i = 1; i <= SIZ; i++) {
            if (pref1[i][j] == 1) pref2[i][j] = 1;
            if (pref1[i][j] >= 1) sum++;
        }
    }

    for (int j = 1; j <= SIZ; j++)
        for (int i = 1; i <= SIZ; i++) pref2[i][j] += pref2[i - 1][j];
    for (int i = 1; i <= SIZ; i++)
        for (int j = 1; j <= SIZ; j++) pref2[i][j] += pref2[i][j - 1];

    const int res = SIZ * SIZ - sum;
    for (int i = 0; i < N; i++) {
        int x = pref2[D[i]][R[i]] - pref2[U[i] - 1][R[i]] - pref2[D[i]][L[i] - 1] + pref2[U[i] - 1][L[i] - 1];
        cout << res + x << endl;
    }
}