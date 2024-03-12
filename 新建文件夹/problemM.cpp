#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 100100;

int from[N], id[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, k;
    cin >> n >> k;
    vector<i64> w(N, 1e16), dp(N, 1e16);
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    i64 ma = k;
    dp[k] = 0;
    for (int i = 1; i <= n; i++)
    {
        ma = max(ma, 1ll * l[i]);
        if (w[l[i]] > r[i])
        {
            w[l[i]] = r[i];
            id[l[i]] = i;
        }
    }
    for (int i = k + 1; i <= ma; i++)
    {
        if (w[i] > N)
            continue;
        i64 ans = (w[i] - 1) / k * i, it = k;
        for (int j = k + 1; j < i; j++)
        {
            if (ans > dp[j] + (w[i] - 1) / j * i)
            {
                ans = dp[j] + (w[i] - 1) / j * i;
                it = j;
            }
        }
        dp[i] = ans, from[i] = it;
    }
    i64 ans = dp[ma];
    vector<int> use(n + 1);
    int it = ma;
    while (it != k)
    {
        use[id[it]] = true;
        it = from[it];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!use[i])
        {
            ans += 1ll * (r[i] - 1ll) / ma * l[i];
        }
    }
    cout << ans << endl;
    return 0;
}