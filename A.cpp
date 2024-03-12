#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, v;
    cin >> n >> v;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    double l = 0, r = v;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    auto check = [&](double x) {
        for (int i = 0; i < n; i++)
        {
            double si = 1.0 * a[i] / sum * x;
            if (si < x)
                return false;
        }
        return true;
    };
    while (abs(l - r) > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return 0;
}