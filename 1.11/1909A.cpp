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
    vector<two> all(n);
    for (int i = 0; i < n; i++)
    {
        cin >> all[i][0] >> all[i][1];
    }
    vector<int> fl(4);
    for (int i = 0; i < n; i++)
    {
        if (all[i][0] > 0)
            fl[0] = 1;
        if (all[i][0] < 0)
            fl[1] = 1;
        if (all[i][1] > 0)
            fl[2] = 1;
        if (all[i][1] < 0)
            fl[3] = 1;
    }
    if (count(fl.begin(), fl.end(), 1) == 4)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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