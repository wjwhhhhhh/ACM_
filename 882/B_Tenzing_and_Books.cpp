#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, x;
    cin >> n >> x;
    int ans = 0;
    auto check = [&](int te) {
        int tem = x;
        while (tem || te)
        {
            if (tem % 2 == 0 && te % 2)
                return false;
            tem /= 2, te /= 2;
        }
        return true;
    };
    for (int t = 0; t < 3; t++)
    {
        bool st = true;
        for (int i = 0; i < n; i++)
        {
            int tem;
            cin >> tem;
            if (st && check(ans | tem))
                ans |= tem;
            else
                st = false;
        }
    }
    bool fl = (ans == x);
    if (fl)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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