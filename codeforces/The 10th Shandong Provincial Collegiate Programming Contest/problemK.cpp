#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e4;
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
void solve()
{
    int a, p;
    cin >> a >> p;
    if (a & 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        int M = 1 << p;
        int len = (p - 1 + a) / a * 2, r = (1 << p) / len, l = 1;
        if (l == r)
        {
            cout << 1 << '\n';
            return;
        }
        auto check = [&](int x) { return qmi(a, x, M) == qmi(x, a, M); };
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(M - len * mid) && check(len * (M - len * (mid - 1))))
                l = mid;
            else
                r = mid - 1;
        }
        int ans = (1 << p) / len - (M - len * l - 1) / len;
        ans += (M - len * l - 1) / a;
        cout << ans << '\n';
    }
}
void solve(int n)
{
    int a, p;
    cin >> a >> p;
    int M = 1 << p;
    int ans = 0;
    for (int i = 0; i <= 100 && i <= M; i++)
    {
        if (qmi(a, i, M) == qmi(i, a, M))
            cout << i << endl;
    }
    cout << ans << endl;
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
    // for (int i = 2; i <= 100; i += 2)
    // {
    //     for (int j = 1; j <= 30; j++)
    //     {
    //         int M = 1 << j;
    //         if (qmi(i, M, M) != qmi(M, i, M))
    //             cout << i << " " << j << endl;
    //     }
    // }
    return 0;
}