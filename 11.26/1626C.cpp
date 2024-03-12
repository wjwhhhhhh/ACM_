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
    vector<i64> k(n + 1), h(n + 1), be(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        be[i] = k[i] - h[i] + 1;
    vector<i64> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        i64 ing = be[i], id;
        //cout << ing << endl;
        for (int j = i - 1; j >= 0; j--)
        {
            if (k[j] < ing)
            {
                id = j;
                break;
            }
            else
            {
                chmin(ing, be[j]);
            }
        }
        dp[i] = dp[id] + (k[i] - ing + 1) * (k[i] - ing + 2) / 2;
    }
    cout << dp.back() << endl;
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