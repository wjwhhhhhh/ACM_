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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    multiset<int> has;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        has.insert(a[i]);
    }
    i64 ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        multiset<int> all;
        for (auto &c : has)
            if (c >> i & 1)
                all.insert(c);
        if (all.size() > 1)
        {
            ans += 1 << i;
            swap(all, has);
        }
    }
    vector<int> all;
    for (int i = 0; i < n; i++)
    {
        if ((ans & a[i]) == ans)
            all.push_back(i + 1);
    }
    //cout << ans << endl;
    //  cout << ans[0] << " " << ans[1] << endl;
    // cout << (50 & 22) << endl;
    // cout << (17 & 50) << endl;
    cout << all[0] << " " << all[1] << endl;
    return 0;
}