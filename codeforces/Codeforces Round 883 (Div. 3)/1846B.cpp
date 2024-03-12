#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    string a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    vector<char> ans;
    auto check = [&](char t) {
        for (int i = 0; i < 3; i++)
        {
            bool fl = true;
            for (int j = 0; j < 3; j++)
                if (a[i][j] != t)
                    fl = false;
            if (fl)
            {
                ans.push_back(t);
                return;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            bool fl = true;
            for (int j = 0; j < 3; j++)
                if (a[j][i] != t)
                    fl = false;
            if (fl)
            {
                ans.push_back(t);
                return;
            }
        }
        bool fl = true;
        for (int j = 0; j < 3; j++)
            if (a[j][j] != t)
                fl = false;
        if (fl)
        {
            ans.push_back(t);
            return;
        }
        fl = true;
        for (int j = 0; j < 3; j++)
            if (a[j][2 - j] != t)
                fl = false;
        if (fl)
        {
            ans.push_back(t);
            return;
        }
    };
    check('X');
    check('O');
    check('+');
    if (ans.size() == 1)
    {
        cout << ans[0] << '\n';
    }
    else
        cout << "DRAW" << '\n';
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