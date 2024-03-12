#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1), s(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + cnt[i];
    vector<int> all;
    for (int i = 0; (1 << i) <= 2 * n; i++)
    {
        all.push_back(1 << i);
    }
    int ans = 1e9;
    auto get = [&](int x) { return *lower_bound(all.begin(), all.end(), x) - x; };
    for (int i = n; i > 0; i--)
    {
        for (auto j : all)
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (j >= s[mid])
                    l = mid;
                else
                    r = mid - 1;
            }

            if (chmin(ans, j - s[l] + get(s[i - 1] - s[l]) + get(s[n] - s[i - 1])))
            {
                // cout << i << " " << j << l << endl;
            }
        }
    }
    cout << ans << endl;
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