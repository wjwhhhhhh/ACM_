#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fir(i, 1, n + 1) cin >> a[i];
    a[1] = 0;
    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 2; j <= 1 << i; j++)
        {
            if (a[j] < a[j - 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        for (int j = 1; j <= 1 << i; j++)
            a[j] = 0;
    }
    for (int j = 2; j <= n; j++)
    {
        if (a[j] < a[j - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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