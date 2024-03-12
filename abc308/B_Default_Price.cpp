#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> has(n);
    for (int i = 0; i < n; i++)
        cin >> has[i];
    map<string, int> worth;
    int last, idx = 0;
    for (int i = 0; i < m; i++)
    {
        string tem;
        cin >> tem;
        worth[tem] = idx++;
    }
    cin >> last;
    vector<int> dui(m);
    for (int i = 0; i < m; i++)
        cin >> dui[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (worth.find(has[i]) == worth.end())
            ans += last;
        else
            ans += dui[worth[has[i]]];
    }
    cout << ans << endl;
    return 0;
}