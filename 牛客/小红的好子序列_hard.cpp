#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
struct Comb
{
#define ll long long
    ll n, p;
    vector<ll> fac, inv; // 阶乘 逆元

    long long qmi(long long k, long long p, long long M)
    {
        long long res = 1;
        while (p)
        {
            if (p & 1)
                res = res * k % M;
            k = k * k % M;
            p >>= 1;
        }
        return res;
    }
    Comb()
    {
    }
    Comb(int a, int b)
    {
        init(a, b);
    }
    void init(int a, int b)
    {
        n = a, p = b;
        fac.resize(n + 5), inv.resize(n + 5);
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;
        inv[n] = qmi(fac[n], p - 2, p);
        for (int i = n; i; i--)
            inv[i - 1] = inv[i] * i % p;
    }
    int C(int n, int m)
    {
        if (n < m || m < 0)
            return 0;
        return (fac[n] * inv[m] % p) * inv[n - m] % p;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    i64 ans = 0;
    Comb co(n, M);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]].push_back(i);
    }
    vector<int> l, r;
    for (auto [x, y] : mp)
    {
        r.push_back(y.size());
    }
    vector<vector<int>> len(n + 1);
    for (int i = 0; i < r.size(); i++)
    {
        i64 last = 1;
        for (int j = 1; j <= r[i]; j++)
        {
            last = (last + (co.C(n - r[i], j))) % M;
            ans = (ans + last * co.C(r[i], j)) % M;
            len[j].push_back(co.C(r[i], j));
        }
    }
    for (int le = 1; 2 * le <= n; le++)
    {
        if (len[le].size() == 0)
            continue;
        i64 sum = 0;
        for (auto x : len[le])
            sum = (sum + x) % M;
        i64 tem = 0;
        for (auto x : len[le])
        {
            tem = (tem + x * (sum - x + M) % M) % M;
        }
        tem = (tem * co.qmi(2, M - 2, M)) % M;
        ans = (ans - tem + M) % M;
    }
    cout << ans << endl;
    return 0;
}