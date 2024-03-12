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
    i64 big = pow(10, n);
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    vector<i64> all;
    i64 xi = 0;
    while (xi * xi <= big)
    {
        all.push_back(xi * xi);
        xi++;
    }
    i64 ans = 0;
    i64 cnt = 1;
    for (auto c : all)
    {
        string ing = to_string(c);
        while (ing.size() < n)
        {
            ing = '0' + ing;
        }
        sort(ing.begin(), ing.end());
        if (ing != a)
            continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}