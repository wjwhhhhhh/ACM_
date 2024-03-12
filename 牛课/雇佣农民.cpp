#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n;
    cin >> n;
    vector<i64> fac(N), sum(N);
    for (int i = 1; i < N; i++)
    {
        fac[i] = fac[i - 1] + i;
        sum[i] = sum[i - 1] + fac[i];
    }
    int l = 1, r = N - 1;
    auto check = [&](int x) { return sum[x] >= n; };
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    vector<int> ans(l + 1);
    for (int i = 1; i <= l; i++)
    {
        if (n && n >= (l - i + 1))
        {
            i64 si = min(i * 1ll, n / (l - i + 1));
            n -= si * (l - i + 1);
            ans[i] = si;
        }
        else
            ans[i] = 0;
    }
    cout << l << endl;
    for (int i = 1; i <= l; i++)
        cout << ans[i] << " ";
    return 0;
}