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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> w(n), ww(n);
    for (int i = 0; i < n; i++)
    {
        int si = 0, res = 0;
        for (auto c : a[i])
        {
            si += (c == '(' ? 1 : -1);
            chmin(res, si);
        }
        w[i] = si, ww[i] = res;
    }
    int ing = 0;
    vector<int> ans;
    vector<int> tem, tp;
    for (int i = 0; i < n; i++)
    {
        if (ww[i] >= 0 && w[i] >= 0)
        {
            ing += w[i];
            ans.push_back(i);
        }
        else if (w[i] >= 0)
            tem.push_back(i);
        else
            tp.push_back(i);
    }
    sort(tem.begin(), tem.end(), [&](int x, int y) { return ww[x] > ww[y]; });
    for (auto x : tem)
    {
        if (ing + ww[x] < 0)
        {
            cout << "impossible" << endl;
            return 0;
        }
        ing += w[x];
        ans.push_back(x);
    }
    sort(tp.begin(), tp.end(), [&](int x, int y) { return ww[x] < ww[y] || (ww[x] == ww[y] && w[x] > w[y]); });
    for (auto x : tp)
    {
        if (ing + ww[x] < 0)
        {
            cout << "impossible" << endl;
            return 0;
        }
        ing += w[x];
        ans.push_back(x);
    }
    if (ing != 0)
    {
        cout << "impossible" << endl;
        return 0;
    }
    for (auto c : ans)
        cout << c + 1 << '\n';
    return 0;
}