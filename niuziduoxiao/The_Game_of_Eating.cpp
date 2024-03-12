#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<int, int>> a[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i].push({x, j});
        }
    set<int> ans;
    k--;
    while (k >= 0)
    {
        int id = k % n;
        while (ans.find(a[id].top().second) != ans.end())
        {
            a[id].pop();
        }
        ans.insert(a[id].top().second);
        k--;
    }
    for (auto i : ans)
        cout << i + 1 << " ";
    cout << endl;
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