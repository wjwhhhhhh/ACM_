#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    string need;
    cin >> need;
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        set<int> has;
        for (int j = l[i]; j <= r[i]; j++)
            has.insert(j);
        while (cnt < need.size())
        {
            if (has.find(need[cnt]) != has.end())
                has.erase(need[cnt]);
            cnt++;
            if (cnt == need.size() && i == m - 1 && has.size() == 0)
            {
                cout << "NO" << endl;
                return;
            }
            if (has.size() == 0)
                break;
        }
    }
    if (cnt == need.size())
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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