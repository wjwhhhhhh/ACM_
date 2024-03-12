#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6;
void solve()
{
    int n, k;
    cin >> n >> k;
    pair<int, int> a1, a2, a3;
    a1 = {1, 0}, a2 = {0, 1};
    for (int i = 2; i < k; i++)
    {
        a3 = {a2.first + a1.first, a2.second + a1.second};
        if (a3.second > N)
            a3.second = N;
        swap(a1, a2);
        swap(a3, a2);
        if (a2.second == N)
            break;
    }
    int ans = 0;
    if (a2.second == N)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int tem = n;
        if (i * a2.first >= tem)
            break;
        tem -= i * a2.first;
        if (tem % a2.second == 0 && tem / a2.second >= i)
            ans++;
    }
    cout << ans << '\n';
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