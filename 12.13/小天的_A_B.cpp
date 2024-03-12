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
const int M = 998244353;
template <class T> T qmi(T k, long long p = M - 2, long long P = M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll * res * k % P;
        k = 1ll * k * k % P;
        p >>= 1;
    }
    return res % P;
}
const int Max = 1e9;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> z, f, lin;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            z.insert(i);
        else if (a[i] == 0)
            lin.insert(i);
        else
            f.insert(i);
    }
    while (m--)
    {
        int fl, x, v;
        cin >> fl >> x >> v;
        x--;
        if (fl == 1)
        {
            if (a[x] > 0)
                z.erase(x);
            else if (a[x] == 0)
                lin.erase(x);
            else
                f.erase(x);
            a[x] += v;
            if (a[x] > 0)
                z.insert(x);
            else if (a[x] == 0)
                lin.insert(x);
            else
                f.insert(x);
        }
        else
        {
            v--;
            auto it = z.lower_bound(x);
            auto iy = lin.lower_bound(x);
            if (it != z.end() && *it <= v)
            {
                i64 ans = a[max(x, (*it) - 1)];
                for (int i = max(x, (*it) - 1) + 1; i <= v; i++)
                {
                    ans = 2ll * max(1ll * a[i], ans);
                    if (ans >= Max)
                    {
                        ans %= M;
                        ans *= qmi(2, v - i);
                        ans %= M;
                        break;
                    }
                }
                cout << ans << '\n';
            }
            else if (iy != lin.end() && *iy <= v)
            {
                cout << 0 << '\n';
            }
            else
            {
                i64 ans = a[max(x + 1, v - 50) - 1];
                for (int i = max(x + 1, v - 50); i <= v; i++)
                {
                    ans = 2ll * max(ans, 1ll * a[i]);
                }
                cout << (ans % M + M) % M << '\n';
            }
        }
    }
    return 0;
}