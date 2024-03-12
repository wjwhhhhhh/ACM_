#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cnt(n);
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        cnt[a].push_back(i);
    }
    vector<int> w(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        w[a] = max(b + 1,w[a]);
    }
    int ans = 0;
    function<void(int)> dfs = [&](int u) {
        if (w[u])
        {
            ans++;
            for (auto x : cnt[u])
                w[x] = max(w[x], w[u] - 1);
        }
        for (auto x : cnt[u])
            dfs(x);
    };
    dfs(0);
    cout << ans << endl;
    return 0;
}