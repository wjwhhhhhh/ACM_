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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    string tm;
    cin >> tm;
    tm = " " + tm;
    vector<vector<int>> pre(n + 2, vector<int>(k + 1));
    vector<vector<int>> suf(n + 2, vector<int>(k + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            if (tm[i] == '0')
                pre[i][j] = pre[i - 1][j] + 1;
            else if (j)
                pre[i][j] = pre[i - 1][j - 1] + 1;
            else
                pre[i][j] = 0;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j <= k; j++)
            if (tm[i] == '0')
                suf[i][j] = suf[i + 1][j] + 1;
            else if (j)
                suf[i][j] = suf[i + 1][j - 1] + 1;
            else
                suf[i][j] = 0;
    }
    // cout << suf[n][0] << endl;
    for (int i = 1; i <= n; i++)
    {
        chkmax(pre[i][0], pre[i - 1][0]);
        for (int j = 1; j <= k; j++)
        {
            chkmax(pre[i][j], pre[i][j - 1]);
            chkmax(pre[i][j], pre[i - 1][j]);
        }
    }
    for (int i = n; i > 0; i--)
    {
        chkmax(suf[i][0], suf[i + 1][0]);
        for (int j = 1; j <= k; j++)
        {
            chkmax(suf[i][j], suf[i][j - 1]);
            chkmax(suf[i][j], suf[i + 1][j]);
        }
    }
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + (tm[i] == '0');
    vector<int> f(n + 1, -1e7);
    f[0] = pre[n][k];
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            int ci = s[r] - s[l - 1];
            if (ci > k)
                continue;
            chkmax(f[len], pre[l - 1][k - ci]);
            chkmax(f[len], suf[r + 1][k - ci]);
        }
    }
    for (int a = 1; a <= n; a++)
    {
        i64 ans = 0;
        for (int j = 0; j <= n; j++)
        {
            chkmax(ans, 1ll*a * f[j] + j);
        }
        cout << ans << " ";
    }
    cout << endl;
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