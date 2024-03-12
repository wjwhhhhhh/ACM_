#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9 + 7;
vector<i64> divisor(i64 n)
{
    vector<i64> p;
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i), p.push_back(n / i);
        }
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    return p;
}
long long qmi(long long k, long long p = M - 2)
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
i64 euler_phi(i64 n)
{ //欧拉函数
    i64 res=1;
    for(i64 i=2; i*i<=n; i++)
        if(n%i==0)
        {
            n/=i,res=res*(i-1);
            while(n%i==0) n/=i,res=res*i;
        }
    if(n>1) res=res*(n-1);
    return res;
}
void solve()
{
    i64 n;
    cin >> n;
    auto p = divisor(n);
    i64 ans = 0;
    for (auto i : p)
    {
        ans = (ans + euler_phi(i) * qmi(n, n / i) % M) % M;
    }
    ans = ans * qmi(n) % M;
    cout << ans << endl;
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