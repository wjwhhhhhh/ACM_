#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    vector<i64> fac(40), w(40);
    fac[0] = 1;
    for (int i = 1; i < 40; i++)
        fac[i] = fac[i - 1] * 2;
    w[1] = 1;
    for (int i = 2; i < 40; i++)
        w[i] = w[i - 1] + fac[i - 1];
    int n, m;
    cin >> n >> m;
    n = n % m;
    if (n == 0)
    {
        cout << "0" << endl;
        return;
    }
    i64 ans = 0;
    while (n)
    {
        bool fl = false;
        for (int i = 0; i < 40; i++)
        {
            if (m % fac[i] == 0 && m / fac[i] <= n)
            {
                ans += m / fac[i] * w[i];
                n -= m / fac[i];
                break;
            }
            if (i == 39)
                fl = true;
        }
        if (fl)
            break;
    }
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    else
        cout << "-1" << endl;
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