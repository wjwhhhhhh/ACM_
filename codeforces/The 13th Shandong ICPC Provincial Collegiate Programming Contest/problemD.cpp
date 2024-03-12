#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    int l = 1, r = 0x3f3f3f3f;
    auto check = [&](int x) {
        vector<int> need, has;
        for (int i = 0; i < n; i++)
        {
            if (v[i] < x)
                need.push_back(w[i]);
            else
                has.push_back(w[i] + v[i] - x);
        }
        sort(need.begin(), need.end());
        sort(has.begin(), has.end());
        if (need.size() > has.size())
            return false;
        for (int i = need.size() - 1, j = has.size() - 1; i >= 0; i--, j--)
        {
            if (has[j] < need[i])
                return false;
        }
        return true;
    };
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
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