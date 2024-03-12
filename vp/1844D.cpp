#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> has;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            has.push_back(i);
    vector<int> ans(n + 1);
    cerr << has.size() << endl;
    for (int i = 2; i <= n; i++)
    {
        unordered_set<int> from;
        for (auto x : has)
        {
            if (x >= i)
                break;
            from.insert(ans[i - x]);
        }
        int idx = 0;
        while (from.find(idx) != from.end())
            idx++;
        ans[i] = idx;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << char(ans[i] + 'a');
    // cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}