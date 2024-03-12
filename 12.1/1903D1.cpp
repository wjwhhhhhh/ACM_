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
const int M = 60;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        vector<i64> tr(a);
        i64 k;
        cin >> k;
        i64 ans = 0;
        for (int i = M; i >= 0; i--)
        {
            __int128 si = 0;
            for (int j = 0; j < n; j++)
            {
                if (tr[j] >> i & 1)
                    continue;
                else
                {
                    si += (1ll << i) - tr[j] % (1ll << i);
                }
            }
            if (si <= k)
            {
                k -= si;
                ans += 1ll << i;
                for (int j = 0; j < n; j++)
                {
                    if (tr[j] >> i & 1)
                        continue;
                    else
                    {
                        tr[j] = 1ll << i;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}