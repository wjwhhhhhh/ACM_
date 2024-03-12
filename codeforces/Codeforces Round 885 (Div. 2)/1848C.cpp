#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    int last = -1;
    bool fl = true;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    function<int(int, int)> check = [&](int x, int y) {
        if (x == 0)
            return 0;
        if (y == 0)
            return 1;
        if (y & 1)
        {
            if (x & 1)
                return 2;
            else
                return 0;
        }
        else if (x & 1)
        {
            return (check(y, abs(x - y)) + 1) % 3;
        }
        else
        {
            if (y % 4 != 0)
            {
                int si = x / 2;
                if (si & 1)
                    return 2;
                else
                    return 0;
            }
            else
            {
                int len = 1, tem = y;
                while (tem % 2 == 0)
                {
                    tem /= 2;
                    len *= 2;
                }
                int si = x / 2;
                if (si % len == len / 2)
                    return 2;
                else if (si % len == 0)
                    return 0;
                else
                    return 1;
            }
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
            continue;
        int tem = check(a[i], b[i]);
        // cout << tem << endl;
        if (last == -1)
            last = tem;
        if (last != tem)
            fl = false;
    }
    if (fl)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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