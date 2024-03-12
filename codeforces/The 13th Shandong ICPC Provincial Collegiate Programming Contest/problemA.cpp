#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    bool fl = true;
    int last = 0;
    i64 sum = 0;
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    for (int j = 0; j < n; j++)
    {
        int i = o[j];
        sum += 1ll * (a[i] - last) * k;
        if (sum < b[i])
        {
            fl = false;
            break;
        }
        sum -= b[i];
        last = a[i];
    }
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