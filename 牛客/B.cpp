#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        in[a]++, in[b]++;
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (in[i] >= 2)
            ans--;
    }
    cout << ans << endl;
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
}