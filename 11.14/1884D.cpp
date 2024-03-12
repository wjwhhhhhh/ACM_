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
    i64 n;
    cin >> n;
    vector<vector<int>> fac(n + 1);
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j += i)
        {
            fac[i].push_back(j);
        }
    }
    vector<i64> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<i64> w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        i64 sum = 0;
        for (auto c : fac[i])
            sum += cnt[c];
        w[i] = (sum) * (sum - 1) / 2;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            w[i] -= w[j];
        }
    }
    for (int i = n; i > 0; i--)
    {
        if (cnt[i] != 0)
        {
            for (int j = i; j <= n; j += i)
            {
                w[j] = 0;
            }
        }
    }
    cout << accumulate(w.begin(), w.end(), 0ll) << endl;
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