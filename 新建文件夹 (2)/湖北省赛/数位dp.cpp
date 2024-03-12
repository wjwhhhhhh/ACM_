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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    int ans = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if ((a[i] - '0') % 2 == 0)
        {
            break;
        }
        else
            ans++;
    }
    cout << ans << endl;
    return 0;
}