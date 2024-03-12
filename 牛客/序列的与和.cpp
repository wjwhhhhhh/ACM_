#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
using i128 = __int128;
using ui64 = unsigned long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    vector<ui64> st(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    function<void(int)> dfs = [&](int u) {
        if (u == n)
        {
            ui64 res = ~0;
            for (int i = 0; i < n; i++)
            {
                if (st[i])
                {
                    res &= a[i];
                }
            }
            int cnt;
            while (res)
            {
                // dug(res);
                if (res & 1)
                    cnt++;
                res >>= 1ll;
            }
            if (cnt == k)
                ans++;
            return;
        }
        dfs(u + 1);
        st[u] = true;
        dfs(u + 1);
        st[u] = false;
    };
    dfs(0);
    cout << ans << endl;
    return 0;
}