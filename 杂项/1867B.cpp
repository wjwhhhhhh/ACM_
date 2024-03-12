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
    int n;
    cin >> n;
    string a;
    cin >> a;
    string ans(n + 1, '0');
    int si = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            si++;
    }
    for (int i = 0; i <= n / 2; i++)
    {
        if (i < si)
            ans[i] = '0';
        else if ((i - si) % 2 == 0)
            ans[i] = '1';
        else if (n % 2 == 1)
            ans[i] = '1';
        else
            ans[i] = '0';
    }
    for (int i = 0; i <= n / 2; i++)
        ans[n - i] = ans[i];
    cout << ans << endl;
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