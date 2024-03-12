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
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ing = 0;
    int ans = 0;
    bool fl = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
            ing++;
        else
        {
            if (ing > 2)
                fl = true;
            if (ing > 0)
            {
                if (ing == 1)
                    ans++;
                else
                    ans += 2;
            }
            ing = 0;
        }
    }
    if (ing > 2)
        fl = true;
    if (ing > 0)
    {
        if (ing == 1)
            ans++;
        else
            ans += 2;
    }
    if (fl)
        cout << 2 << endl;
    else
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