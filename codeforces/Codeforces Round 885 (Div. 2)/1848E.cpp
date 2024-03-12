#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
int M;
long long qmi(long long k, long long p = M - 2, long long P = M)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
const int N = 2e6 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t, q;
    vector<int> mp(N);
    cin >> t >> q >> M;
    vector<int> inv(N);
    inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = (i64)(M - M / i) * inv[M % i] % M;
    }
    int ans = 1;
    int cnt = 0;
    int ssi = 0;
    auto mul = [&](int d) {
        while (d % 2 == 0)
            d /= 2;
        for (int x = 3; x <= d / x; x += 2)
        {
            int si = 0;
            while (d % x == 0)
            {
                si++;
                d /= x;
            }
            if ((mp[x] + 1) % M)
            {
                ans = (i64)ans * inv[mp[x] + 1] % M;
            }
            else
                cnt--;

            (mp[x] += si) %= M;

            if ((mp[x] + 1) % M)
                ans = (i64)ans * (mp[x] + 1) % M;
            else
                cnt++;
        }
        if (d != 1)
        {
            if (d >= N)
            {
                ans = ans * 2 % M;
                return;
            }
            if ((mp[d] + 1) % M)
            {
                ans = (i64)ans * inv[mp[d] + 1] % M;
            }
            else
                cnt--;

            (mp[d] += 1) %= M;

            if ((mp[d] + 1) % M)
                ans = (i64)ans * (mp[d] + 1) % M;
            else
                cnt++;
        }
    };
    mul(t);
    for (int i = 0; i < q; i++)
    {
        int d;
        cin >> d;
        mul(d);
        cout << (cnt ? 0 : ans) << '\n';
    }
    return 0;
}