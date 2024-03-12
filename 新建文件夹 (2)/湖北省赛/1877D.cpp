#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
vector<i64> divisor(i64 n)
{
    vector<i64> p;
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i);
            if (n / i != i)
                p.push_back(n / i);
        }
    }
    return p;
}
const int M = 998244353;
template <class T> T qmi(T k, long long p = M - 2, long long P = M)
{
    T res = 1;
    while (p)
    {
        if (p & 1)
            res = 1ll * res * k % P;
        k = 1ll * k * k % P;
        p >>= 1ll;
    }
    return res % P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]].push_back(i + 1);
    i64 res = 0;
    vector<int> all;
    for (auto [x, cnt] : mp)
        all.push_back(x);
    reverse(all.begin(), all.end());
    vector<int> w(n + 1, 1);
    for (int i = 0; i < all.size(); i++)
    {
        i64 ans = 0, si = 0;
        for (auto c : mp[all[i]])
        {
            auto p = divisor(c);
            for (auto tr : p)
            {
                ans += w[tr];
                w[tr] = 0;
            }
        }
        si = qmi(2ll, ans) % M;
        si = (si - 1 + M) % M;
        si = si * qmi(2ll, n - ans) % M;
        res = (res + si * all[i] % M) % M;
        n -= ans;
    }
    cout << res << endl;
    return 0;
}