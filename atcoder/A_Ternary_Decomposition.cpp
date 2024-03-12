#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 N = 1e18;
void solve()
{
    i64 a1, a2;
    cin >> a1 >> a2;
    if (a1 < a2)
    {
        cout << "No" << endl;
        return;
    }
    if (a1 == a2)
    {
        cout << "Yes" << endl;
        return;
    }
    __int128 n = a1, k = a2, x = 1;
    for (int i = 0; i < 50; i++)
        x *= 3ll;
    i64 cnt = 0;
    for (int i = 50; ~i; i--)
    {
        while (x <= n)
        {
            // cout << (int)x << endl;
            n -= x, cnt++;
        }
        x /= 3ll;
    }
    cnt = k - cnt;
    if (cnt&&cnt % 2 == 0)
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