#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 998244353;
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
using u64 = unsigned long long;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void solve()
{

    int n, k;
    cin >> n >> k;
    if (n & 1)
    {
        cout << "0" << '\n';
        return ;
    }
    Comb co(2 * n, N);
    vector<u64> d(n);
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        a--;
        auto x=rng();
        d[a]^=x,d[b]^=x;
    }
    for(int i=1;i<n;i++)
    {
        d[i]^=d[i-1];
    }
    map<u64,int> cnt;
    for(auto x:d)
    {
        cnt[x]++;
    }
    i64 ans=1;
    for(auto [x,y]:cnt)
    {
        ans=ans*(co.C(x,x/2)-co.C(x,x/2+1))%N;
    }
    cout<<ans<<'\n';
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