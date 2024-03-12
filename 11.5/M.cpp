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
using P = pair<int, int>;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int l = 1, r = 1e9;
    auto get = [&](int len) {
        vector<int> aa(n), bb(n);
        for (int i = 0; i < n; i++)
        {
            aa[i] = (a[i] >= len);
            bb[i] = (b[i] >= len);
        }
        vector<int> sa(n + 1), sb(n + 1);
        for (int i = 0; i < n; i++)
        {
            sa[i + 1] = sa[i] + aa[i];
            sb[i + 1] = sb[i] + bb[i];
        }
        int ans = sa[n];
        int res = sa[n] - sb[0] + sa[0];
        for (int i = 1; i <= n; i++)
        {
            chmax(ans, sb[i] - sa[i] + res);
            chmax(res, sa[n] - sb[i] + sa[i]);
        }
        return ans;
    };
    // cout << get(500000000) << endl;
    //  cout << ((n + 1) >> 1) << endl;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        // cout << get(mid) << " " << mid << endl;
        if (get(mid) >= (n + 1) >> 1)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}