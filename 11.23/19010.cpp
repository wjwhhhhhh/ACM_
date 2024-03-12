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
    int n, X;
    cin >> n >> X;
    vector<int> cnt(X + 1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a] = 1;
    }
    int l = 0, r = 200;
    auto check = [&](int x) {
        int ing = x;
        for (int i = 1; i <= X; i++)
        {
            ing--;
            if (ing < 0)
                return false;
            if (cnt[i])
                ing = x;
        }
        for (int i = X - 1; i >= 0; i--)
        {
            ing--;
            if (ing < 0)
                return false;
            if (cnt[i])
                ing = x;
        }
        return true;
    };
    // if (check(0))
    //     cout << "ok";
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