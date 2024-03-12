#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        i64 lcm = 1;
        vector<int> ans;
        for (int i = 1; i < n; i++)
        {
            ans.push_back(n / 2 + i);
            lcm = lcm * (n / 2 + i) / __gcd(lcm, n / 2 + i);
        }
        i64 need = lcm;
        for (int i = 0; i < n - 1; i++)
        {
            need -= lcm / ans[i];
        }
        for (int i = 0; i < n - 1; i++)
            cout << ans[i] << " ";
        cout << lcm / need << " ";
        cout << endl;
    }
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