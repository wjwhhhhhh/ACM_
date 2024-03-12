#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, t;
    cin >> n >> t;
    vector<i64> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return l[x] < l[y]; });
    int si = 0;
    i64 ans = 0, sum = r[o[0]];
    for (int i = 1; i < n; i++)
    {
        i64 tem = min(l[o[i]] - l[o[i - 1]], sum);
        ans += tem;
        sum -= tem;
        sum += r[o[i]];
    }
    ans += min(t - l[o[n - 1]] + 1, sum);
    cout << ans << endl;
    return 0;
}