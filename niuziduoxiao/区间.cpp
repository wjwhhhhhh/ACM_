#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 l, r, t;
    cin >> l >> r >> t;
    i64 x = l, y = r;
    if (y - x >= t)

    {
        cout << "Yes" << endl;
        return;
    }
    for (int i = 62; i >= 0; i--)
    {
        if (t >> i & 1)
        {
            if (!(y >> i & 1))
            {
                cout << "No" << endl;
                return;
            }
            x = 0;
        }
        else if (y >> i & 1 && !(x >> i & 1))
        {
            if (i)
            {
                y |= (1 << i) - 1;
            }
        }
    }
    cout << "Yes" << endl;
    return;
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