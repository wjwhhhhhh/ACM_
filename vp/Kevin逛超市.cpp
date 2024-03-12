#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 998244353;
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
    int n;
    cin >> n;
    auto check = [&](int x) {
        int l = 1, r = n;
        int res = 1;
        while (1)
        {
            res++;
            int mid = l + r >> 1;
            if(x<mid&&mid==l)break;
            else if (x <= mid)
                r = mid;
            else
                l = mid + 1;
        }
        return res;
    };
    for (int i = 1; i <= n; i++)
        cout << check(i) << endl;
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