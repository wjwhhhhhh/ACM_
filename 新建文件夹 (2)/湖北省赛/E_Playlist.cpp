#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int M = 998244353;
template <class T> T qmi(T k, long long p = M - 2, long long P = M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll * res * k % P;
        k = 1ll * k * k % P;
        p >>= 1;
    }
    return res % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<i64> dp(k + 1);
    dp[0] = 1;
    int p = qmi(n);
    for (int i = 0; i <= k; i++)
    {
        for (auto c : a)
        {
            if (c + i > k)
                continue;
            dp[c + i] += dp[i] * p;
            dp[c + i] %= M;
        }
    }
    i64 ans = 0;
    for (int j = 0; j < a[0]; j++)
    {
        if (k - j < 0)
            continue;
        // cout << dp[k - j] << endl;
        ans += dp[k - j];
        ans %= M;
    }
    cout << (ans * p) % M << endl;
    return 0;
}