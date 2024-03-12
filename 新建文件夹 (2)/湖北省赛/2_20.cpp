#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
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
    i64 tr = 1 << 20;
    i64 t;
    cin >> t;
    if (t % tr == 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1e9;
    int ing = ~0;
    bool fl = false;
    for (int i = 0; i < 20; i++)
    {
        if (t >> i & 1)
        {
            if (!fl)
            {
                chmin(ans, max(0, 20 - i));
                fl = true;
            }
            while (t >> i & 1)
                i++;
            int need = ~ing + 1;
            chmin(ans, need + max(0, 20 - i));
            i--;
        }
        else
        {
            ing ^= 1 << i;
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