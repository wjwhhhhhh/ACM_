#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<pair<int, int>> has;
    for (int i = 0; i < n; i++)
    {
        int mi = min(i + 1, n - i);
        if (d[i] > mi)
        {
            cout << "No" << endl;
            return;
        }
        for (int j = 1; j < d[i]; j++)
        {
            g[i - j][j + i] = g[j + i][i - j] = true;
        }
        if (d[i] < mi)
        {
            has.push_back({i - d[i], i + d[i]});
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] |= g[i][k] & g[k][j];
    }
    for (auto [x, y] : has)
    {
        // cout << x << " " << y << endl;
        if (g[x][y] == true)
        {
            cout << x << ' ' << y << endl;
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}