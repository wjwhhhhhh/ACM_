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
const int M = 5e6 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<i64> c(M), dp(M);
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    for (int j = 1; j < M; j++)
        for (int i = (j << 1); i < M; i += j)
            c[j] += c[i];
    i64 ans = 0;
    for (int j = 1; j < M; j++)
        for (int i = (j << 1); i < M; i += j)
        {
            chkmax(dp[i], dp[j] + (c[j] - c[i]) * j);
            chkmax(ans, dp[i] + c[i] * i);
        }
    cout << ans << endl;
    return 0;
}