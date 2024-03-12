#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n <= m)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 1; i <= (n - m); i--)
    {
        if ((n - m) % i == 0)
        {
            int b = (n - m) / i, a = n - b;
            if (b > m)
            {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
    cout << "-1" << endl;
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