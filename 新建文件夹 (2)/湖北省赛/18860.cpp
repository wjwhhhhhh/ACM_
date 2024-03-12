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
    int n;
    cin >> n;
    if (n <= 6)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 3 == 0)
    {
        if (n == 9)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << "1 4 " << n - 5 << endl;
        }
    }
    else
    {
        cout << "YES" << endl;
        cout << "1 2 " << n - 3 << endl;
    }
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