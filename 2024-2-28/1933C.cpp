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
void solve()
{
    int a, b, l;
    cin >> a >> b >> l;
    set<int> ans;
    for (int i = 0; i <= 20; i++)
    {
        i64 t1 = pow(a, i);
        if (t1 > l)
            break;
        for (int j = 0; j <= 20; j++)
        {
            i64 t2 = pow(b, j);
            if (t2 > l)
                break;
            if (l % (t1 * t2) == 0)
                ans.insert(l / (t1 * t2));
        }
    }
    cout << ans.size() << endl;
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