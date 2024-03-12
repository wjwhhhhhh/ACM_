#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1), x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
    x[i] = x[i - 1], y[i] = y[i - 1];
        while (a[i] != 0 && a[i] % 2 == 0)x[i]++, a[i] /= 2;
        while (a[i] != 0 && a[i] % 5 == 0)y[i]++, a[i] /= 5;
    }
    i64 ans = 0;
    auto find = [&](int l, int r, int k)
    {
        if (min(x[r] - x[l - 1], y[r] - y[l - 1]) < k)return 0;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (min(x[r] - x[mid - 1], y[r] - y[mid - 1]) >= k)l = mid;
            else r = mid - 1;
        }
        return l;
    };
    for (int i = 1; i <= n; i++)
    {
        ans += find(1, i, k) - find(1, i, k + 1);
        //cout << find(1, i, k) << endl;
    }
    cout << ans<< '\n';
}
int main()
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