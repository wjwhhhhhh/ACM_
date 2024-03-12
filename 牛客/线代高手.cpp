#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<vector<int>> s(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i] * b[j];
        }
    auto get = [&](int l, int r, int l1, int r1) { return s[l1][r1] - s[l - 1][r1] - s[l1][r - 1] + s[l - 1][r - 1]; };
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int i1 = i; i1 <= n; i1++)
                for (int j1 = j; j1 <= m; j1++)
                {
                    if (get(i, j, i1, j1) <= x)
                        chkmax(ans, (i1 - i + 1) * (j1 - j + 1));
                }
        }
    cout << ans << endl;
    return 0;
}