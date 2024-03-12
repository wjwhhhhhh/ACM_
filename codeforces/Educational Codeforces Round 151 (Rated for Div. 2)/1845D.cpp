#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> has(n);
    for (int i = 0; i < n; i++)
        cin >> has[i];
    int ans = 0, sum = 0;
    n = has.size();
    has.push_back(0), all.push_back(0);
    vector<int> k(n + 2), ba(n + 2);
    k[0] = all[0];
    for (int i = 1; i < n; i++)
        k[i] += all[i] + k[i - 1];
    for (int i = n - 1; ~i; i--)
    {
        if (all[i] > 0)
        {
            int tem = k[i] + (ba[i + 2] > 0 ? ba[i + 2] : 0);
            if (tem > sum)
            {
                ans = k[i];
                sum = tem;
            }
            ba[i] = ba[i + 2] + all[i] - all[i + 1];
        }
    }
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += all[i];
        if (sum1 < 0)
            sum1 = 0;
    }
    if (sum1 > sum)
        ans = 0;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}