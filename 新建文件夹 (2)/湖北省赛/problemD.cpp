#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
const int N = 1e5;
void solve()
{
    int n, k;
    cin >> k >> n;
    vector<i64> fac(1, 1), sum(1, 0);
    for (int i = 1; i < 50; i++)
    {
        fac.push_back(fac.back() * k);
        sum.push_back(sum.back() + fac.back());
        if (sum.back() >= n)
            break;
    }
    n -= sum[sum.size() - 2];
    string ans;
    for (int i = fac.size() - 1; i > 0; i--)
    {
        ans += char((n - 1) / fac[i - 1] + 10 - k + '0');
        n -= (n - 1) / fac[i - 1] * fac[i - 1];
    }
    // ans.back()++;
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