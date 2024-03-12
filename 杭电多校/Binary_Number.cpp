#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    if (a.size() == 1)
    {
        if (k & 1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return;
    }
    vector<pair<int, int>> has;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            int l = i;
            while (i < n && a[i] == '0')
                i++;
            has.push_back({l, i});
        }
    }
    if (k == 1 && has.size() == 0)
    {
        for (int i = 0; i < n - 1; i++)
            cout << 1;
        cout << 0 << endl;
        return;
    }
    if (k < has.size())
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = has[i].first; j < has[i].second; j++)
                a[j] = '1';
        }
        cout << a << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << 1;
        cout << endl;
    }
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