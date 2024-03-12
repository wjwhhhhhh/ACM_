#include <iostream>
using namespace std;
using PII = pair<int, int>;
PII start, en;
int a[6][6], d[6][6], dx[4] {0, 1, 0, -1}, dy[4] {1, 0, -1, 0}, st[6][6][5];
int main() {
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> a[i][j], d[i][j] = 10000;
    cin >> start.first >> start.second >> en.first >> en.second;
    pair<PII, int> q[72000];
    int hh = 0, tt = 0;
    d[start.first][start.second] = 0;
    q[0] = {{start.first, start.second}, 1};
    while (hh <= tt) {
        pair<PII, int> h = q[hh ++ ];
        PII t = h.first;
        int val = h.second;
        st[t.first][t.second][val] = false;
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < 0 || y < 0 || x >= 6 || y >= 6) continue;
            if (d[t.first][t.second] + a[x][y] * val <= d[x][y]) {
                d[x][y] = d[t.first][t.second] + a[x][y] * val;
                int k = a[x][y] * val % 4 + 1;
                cout << x << ' ' << y << ' ' << d[x][y] << ' ' << t.first << ' ' << t.second << ' ' << k  << endl;
                if (!st[x][y][k]) q[ ++ tt] = {{x, y}, k}, st[x][y][k] = true;
            }
        }
    }
    for (int i = 0; i < 6; i ++ )
        for (int j = 0; j < 6; j ++ )
            cout << d[i][j] << " \n"[j == 5];
    cout << d[en.first][en.second] << endl;
    return 0;
}