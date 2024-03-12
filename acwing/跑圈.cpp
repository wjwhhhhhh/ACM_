#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 L, n;
    cin >> L >> n;
    int last = -1, now = 100 * L;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        string b;
        cin >> a >> b;
        int la = now;
        cout << now << " " << ans << endl;
        if (b == "C")
        {
            now += a;
            int si = now / L - (la + L - 1) / L + 1;
            if (si)
            {
                ans += si;
                if (last == 0)
                    ans--;
                last = 1;
            }
        }
        else
        {
            now -= a;
            int si = la / L - (now + L - 1) / L + 1;
            if (si)
            {
                ans += si;
                if (last == 1)
                    ans--;
                last = 0;
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}