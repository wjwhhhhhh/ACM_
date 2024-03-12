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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<array<int, 3>> ans;
    vector<char> tr;
    auto in = [&](int x, int y, int k, char ch) {
        ans.push_back(array<int, 3>{x, y, k});
        tr.push_back(ch);
    };
    in(1, 1, 1, '/');
    in(n + 1, 1, n + 1, '+');
    i64 to = (1ll << 60) - k;
    while (to != 1)
    {
        if (to & 1)
        {
            in(n + 1, 1, n + 1, '+');
            to--;
        }
        else
        {
            in(n + 1, n + 1, n + 1, '+');
            to >>= 1;
        }
    }
    reverse(ans.begin() + 2, ans.end());
    reverse(tr.begin() + 2, tr.end());
    for (int i = 0; i < 60; i++)
    {
        in(1, 1, 1, '+');
    }
    in(n + 1, 1, n + 1, '-');
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << ans[i][j] << " ";
        cout << tr[i] << endl;
    }
    return 0;
}