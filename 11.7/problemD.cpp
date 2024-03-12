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
using dint = pair<double, int>;
template <class T> struct stable
{
    static const int K = 20;
    vector<array<T, K>> f;
    int si;
    void work(vector<T> &a) // 默认从0开始
    {
        f.resize(a.size());
        si = a.size();
        for (int i = 0; i < si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < si; i++)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual T op(const T &x, const T &y)
    {
        return max(x, y);
    }
};
auto getx(double p)
{
    if (p == 0)
        return (double)1e18;
    else
        return 1.0 / (p);
}
auto gety(double p)
{
    if (p == 1)
        return (double)1e18;
    else
        return 1.0 / (1.0 - p);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    int n;
    cin >> n;
    vector<dint> p(n);
    fir(i, 0, n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end(), greater<dint>());
    vector<dint> pp(p);
    p.clear();
    sort(p.begin(), p.end(), greater<dint>());
    for (int i = 0; i < n; i++)
    {
        if (!p.empty() && pp[i].first == p.back().first)
        {
            p.back().second += pp[i].second;
        }
        else
            p.push_back(pp[i]);
    }
    n = p.size();
    vector<i64> s(n + 1);
    for (int i = n - 1; i >= 0; i--)
        s[i] = s[i + 1] + p[i].second;
    vector<double> py(n);
    for (int i = n - 1; i >= 0; i--)
    {
        py[i] = s[i] * (1 - gety(p[i].first));
    }
    double ans = -1e18;
    stable<double> st;
    st.work(py);
    for (int i = 0; i < n - 1; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if ((s[0] - s[i + 1]) * getx(p[i].first) >= s[mid] * gety(p[mid].first))
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        chmax(ans, s[0] - s[i + 1] + s[l] - max((s[0] - s[i + 1]) * getx(p[i].first), s[l] * gety(p[l].first)));
        if (l != i + 1)
        {
            chmax(ans, s[0] - s[i + 1] + st.ask(i + 1, l - 1));
        }
    }
    cout << max((double)0.0, ans) << endl;
    return 0;
}