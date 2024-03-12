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
    int n, d, m;
    cin >> n >> m >> d;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    if (m == 1)
    {
        cout << (n - 1) / d + 1 << " " << 1 << endl;
        return;
    }
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
    {
        if (i == 0)
        {
            if (a[i] == 1)
                l[i] = 1;
            else
                l[i] = (a[i] - 2) / d + 2;
        }
        else
            l[i] = (a[i] - a[i - 1] - 1) / d + 1 + l[i - 1];
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (i == m - 1)
        {
            r[i] = (n - a[i]) / d + 1;
        }
        else
            r[i] = r[i + 1] + (a[i + 1] - a[i] - 1) / d + 1;
    }
    int ans = (a[1] - 2) / d + 1 + r[1], id = 1;
    if (ans > l[m - 2] + (n - a[m - 2]) / d)
    {
        ans = l[m - 2] + (n - a[m - 2]) / d;
        id = 1;
    }
    else if (ans == l[m - 2] + (n - a[m - 2]) / d)
        id++;
    for (int i = 1; i < m - 1; i++)
    {
        if (ans > l[i - 1] + r[i + 1] + (a[i + 1] - 1 - a[i - 1]) / d)
        {
            ans = l[i - 1] + r[i + 1] + (a[i + 1] - 1 - a[i - 1]) / d;
            id = 1;
        }
        else if (ans == l[i - 1] + r[i + 1] + (a[i + 1] - 1 - a[i - 1]) / d)
            id++;
    }
    cout << ans << " " << id << endl;
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