#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edge(n);
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int fl = 0;
        function<void(int, int)> dfs = [&](int u, int fa) {
            int si = 0;
            for (auto c : edge[u])
            {
                if (c == fa)
                    continue;
                si++;
                dfs(c, u);
            }
            if (si == 1)
                fl++;
        };
        dfs(0, -1);
        if (fl & 1)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}