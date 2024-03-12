#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
struct line
{
    double k, b;
    line(array<double, 2> x, array<double, 2> y)
    {
        if (x[0] == y[0])
            k = 1e9;
        else
            k = (y[1] - x[1]) / (y[0] - x[0]);
        b = y[1] - k * y[0];
        return;
    }
};
bool get(line x, line y, array<double, 2> &ans)
{
    if (x.k == y.k)
        return false;
    ans[0] = -(x.b - y.b) / (x.k - y.k);
    ans[1] = x.k * ans[0] + x.b;
    return true;
}
array<double, 2> s[2];
double lenth(array<double, 2> x, array<double, 2> y)
{
    return sqrt((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
}
bool check(array<double, 2> x)
{
    double xh = lenth(s[0], s[1]);
    return lenth(x, s[0]) <= xh && lenth(x, s[1]) <= xh;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 2; i++)
        cin >> s[i][0] >> s[i][1];
    vector<line> all;
    vector<array<double, 2>> pio(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pio[i][0] >> pio[i][1];
    }
    line p(s[0], s[1]);
    while (m--)
    {
        int h, k;
        cin >> h >> k;
        vector<array<double, 2>> ww;
        array<double, 2> ans;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == h)
                continue;
            // dug(1);
            if (get(p, line(pio[h - 1], pio[i]), ans))
            {
                if (check(ans))
                    ww.push_back(ans);
            }
            // dug(2);
        }
        sort(ww.begin(), ww.end(), [&](auto xx, auto yy) { return lenth(xx, s[0]) < lenth(yy, s[0]); });
        if (ww.size() >= k)
        {
            cout << ww[k - 1][0] << " " << ww[k - 1][1] << '\n';
        }
        else
            cout << "-1" << '\n';
    }
    return 0;
}