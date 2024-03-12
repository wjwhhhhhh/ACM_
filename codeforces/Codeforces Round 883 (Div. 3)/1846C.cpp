#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<i64> has(n), time(n);
    for (int i = 0; i < n; i++)
    {
        priority_queue<int, vector<int>, greater<int>> st;
        for (int i = 0; i < m; i++)
        {
            int tem;
            cin >> tem;
            st.push(tem);
        }
        int last = 0;
        while (last <= h && st.size())
        {
            int t = st.top();
            st.pop();
            last += t;
            if (last <= h)
            {
                has[i]++, time[i] += last;
            }
        }
    }
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    stable_sort(o.begin(), o.end(),
                [&](int x, int y) { return (has[x] == has[y] && time[x] < time[y]) || has[x] > has[y]; });
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (o[i] == 0)
            ans = i;
    }
    cout << ans + 1 << endl;
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