#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<array<pair<int, int>, 26>> b(n);
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        for (int j = 0; j < 26; j++)
        {
            int len = 0;
            while (l < m && a[i][l] == j + 'a')
                l++, len++;
            b[i][j] = {l - len, l - 1};
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (b[x][i].first > b[x][i].second || b[y][i].first > b[y][i].second)
                continue;
            if (b[x][i].first > b[y][i].second || b[x][i].second < b[y][i].first)
                continue;
            else
            {
                ans += min(b[x][i].second, b[y][i].second) - max(b[x][i].first, b[y][i].first) + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}