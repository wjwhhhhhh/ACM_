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
void solve()
{
    int n;
    cin >> n;

    auto get = [&](vector<int> &a) 
    {
        int ma = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            chkmax(ma, a[i] * j);
            res += a[i] * j;
        }
        return res - ma;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> a(n);
        for (int j = 0; j < i; j++)
        {
            a[j] = j + 1;
        }
        for (int j = i, k = n; j < n; j++, k--)
        {
            a[j] = k;
        }
        ans = max(ans, get(a));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}