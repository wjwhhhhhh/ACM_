#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
using p2 = array<int, 2>;
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
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<p2> all(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> all[i][0] >> all[i][1];
    for (int i = 1; i <= n; i++)
    {
        if ((all[i][0] - 1) / a > all[i][1] || (all[i][1] - 1) / b > all[i][0])
        {
            cout << "0" << endl;
            return 0;
        }
    }
    vector<p2> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
    }
    return 0;
}