#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    int l = 0, r = 1e9;
    auto check = [&](int x) {
        vector<int> xa(a), xd(d);
        for (int i = 0; i < n; i++)
        {
            if (i && xa[i - 1] < x)
            {
                int ma = min({x - xa[i - 1], xd[i], xa[i]});
                xa[i - 1] += ma, xa[i] -= ma, xd[i] -= ma;
            }
            if (xa[i] > x)
            {
                if (i == n - 1)
                {
                    if (xa[i] > x)
                        return false;
                }
                else
                {
                    if (xa[i] - xd[i] > x)
                    {
                        return false;
                    }
                    else
                    {
                        int ma = min(x - xa[i], xd[i]);
                        xa[i] -= ma, xd[i] -= ma;
                    }
                }
            }
        }
        return true;
    };
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << check(5) << endl;
    cout << l << endl;
    return 0;
}