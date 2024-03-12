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
int f(int x)
{
    return __builtin_popcount(x);
}
int get(int x)
{
    return (1 << (x + 1)) - 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n, c;
    cin >> n >> c;
    vector<i64> A(n);
    vector<i64> B(n);
    vector<i64> dp(1 << n, 1e18);
    dp[0] = -c;
    fir(i, 0, n) cin >> A[i];
    fir(i, 0, n) cin >> B[i];
    for (int i = 0; i < 1 << n; i++)
    {
        for (int l = 0; l < n; l++)
        {
            if (i >> l & 1)
                continue;
            i64 cost = c, cnt = f(i);
            for (int r = l; r < n; r++)
            {
                if (i >> r & 1)
                    break;
                cost += max(A[r], B[cnt]) - min(A[r], B[cnt]);
                cnt++;
                // cout << cost << ' ' << i << " " << get(r) - get(l - 1) << endl;
                chmin(dp[i + get(r) - get(l - 1)], dp[i] + cost);
            }
        }
    }
    cout << dp.back() << endl;
    return 0;
}