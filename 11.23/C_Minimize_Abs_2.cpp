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
const i64 M = 2e12;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    vector<i64> all;
    for (i64 i = 0; i * i <= M; i++)
    {
        all.push_back(i * i);
    }
    i64 n;
    cin >> n;
    i64 ans = n;
    for (auto c : all)
    {
        if (c > n)
        {
            chmin(ans, c - n);
            continue;
        }
        int l = 0, r = all.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (c + all[mid] <= n)
                l = mid;
            else
                r = mid - 1;
        }
        chmin(ans, n - c - all[l]);
        if (l + 1 < all.size())
        {
            chmin(ans, c + all[l + 1] - n);
        }
    }
    cout << ans << endl;
    return 0;
}