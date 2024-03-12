#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e3 + 10;
vector<int> dp(N, 1e9);
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    k = min(k, n * 12);
    vector<int> f1(k + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= dp[b[i]]; j--)
            f1[j] = max(f1[j], f1[j - dp[b[i]]] + c[i]);
    }
    cout << f1[k] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    dp[1] = 0;
    for (int i = 0; i < N; i++)
    {
        int l = 1, r;
        while (l <= i)
        {
            int te = i / l;
            if (i + te < N)
                dp[i + te] = min(dp[te + i], 1 + dp[i]);
            r = min(i / te, i);
            l = r + 1;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}