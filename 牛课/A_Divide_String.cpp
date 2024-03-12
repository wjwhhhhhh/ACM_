#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    bool fl = false;
    for (int i = 1; i < n; i++)
    {
        if (a.substr(0, i) < a.substr(i))
            fl = true;
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