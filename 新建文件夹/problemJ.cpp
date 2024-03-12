#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 4>> st(n * n + 1);
    for (int i = 1; i <= n * n; i++)
        for (int j = 0; j < 4; j++)
            cin >> st[i][j];
    st[0] = {-1, -1, -1, -1};
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n * n; i++)
    {
        mp[{st[i][0], st[i][2]}] = i;
    }
    vector<vector<int>> ans(n + 1, vector<int>(n + 1));
    ans[1][1] = mp[{-1, -1}];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            int t;
            if (j == 1)
            {
                t = st[ans[i - 1][j]][1];
            }
            else
                t = st[ans[i][j - 1]][3];
            ans[i][j] = t;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j];
            if (j != n)
                cout << " ";
        }
        cout << '\n';
    }
    return 0;
}