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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 t;
    cin >> t;
    string a[4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            a[i] += (t >> (i * 8 + j) & 1) + '0';
        }
    }
    sort(a, a + 4);
    reverse(a, a + 4);
    for (int j = 2; j >= 0; j--)
        a[j] = a[j] + a[j + 1];
    i64 ans = 0;
    // cout << a[0] << endl;
    for (int i = 0; i < a[0].size(); i++)
    {
        ans *= 2;
        ans += a[0][i] == '1';
    }
    cout << ans << endl;
    return 0;
}