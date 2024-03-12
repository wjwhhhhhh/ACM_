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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n);
    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        i64 sum = 0;
        for (int j = 0; j < i; j++)
        {
            chmax(sum, 1ll * (i - j) * min(a[i], a[j]));
        }
        chmax(ans, sum);
        dp[i] = sum;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            chmax(ans, dp[j] + 1ll * (i - j) * min(a[i], a[j]));
        }
    }
    cout << ans << endl;
    return 0;
}