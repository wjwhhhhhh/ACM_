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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    i64 ans = 0, tem;
    for (int i = 0; i < n; i++)
        ans ^= a[i];
    tem = ans;
    if (n % 2 == 0)
    {
        set<int> has;
        for (int j = 0; j < m; j++)
        {
            for (int i = 31; i >= 0; i--)
            {
                if (b[j] >> i & 1)
                    has.insert(i);
            }
        }
        for (int i = 31; i >= 0; i--)
        {
            if (ans >> i & 1 && has.find(i) != has.end())
            {
                ans -= 1ll << i;
            }
        }
        cout << ans << ' ' << tem << endl;
        return;
    }
    cout << ans << ' ';
    for (int j = 0; j < m; j++)
    {
        for (int i = 31; i >= 0; i--)
        {
            if (b[j] >> i & 1 && !(ans >> i & 1))
                ans += 1ll << i;
        }
    }
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