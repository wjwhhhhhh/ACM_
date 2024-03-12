#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
void solve()
{
    string a;
    int n;
    cin >> n;
    cin >> a;
    int l = 0, r = a.size();
    auto check = [&](int x) {
        int len = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '0')
                len++;
            else
            {
                if (len < x)
                    len = -x;
                else if (len == x)
                    len = -max(x - 1, 0);
                else
                    return false;
            }
        }
        if (len > 0)
            return false;

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
    cout << l << endl;
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