#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
int f(i64 x)
{
    return __builtin_popcount(x);
}
const int N = 62, M = 128;
i64 all[N][2][N];
bool w[M][2][2];
i64 len[N][2][2];
void solve()
{
    i64 m, l;
    cin >> m >> l;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    i64 ans = 0;
    for (int j = 0; j <= l; j++)
    {
        bool fl = true;
        for (int i = 0; i < m; i++)
        {
            if (f(i + j) % 2 != a[i])
                fl = false;
        }
        if (fl)
            ans++;
    }
    cout << ans << '\n';
    cout << i64(1e18) << endl;
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