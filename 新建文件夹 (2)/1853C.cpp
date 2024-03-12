#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<i64, i64>> has;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] != 1)
                has.push_back({1, a[i] - 1});
        }
        else
        {
            if (a[i] != a[i - 1] + 1)
                has.push_back({a[i - 1] + 1, a[i] - 1});
        }
    }
    has.push_back({a.back() + 1, 1e18});
    i64 id = 1;
    for (i64 i = k - 1, j = 0, sum = 0; i >= 0; i--)
    {
        while (id - sum > has[j].second - has[j].first + 1)
        {
            sum += has[j].second - has[j].first + 1;
            j++;
        }
        id = id - sum - 1 + has[j].first;
    }
    cout << id << endl;
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