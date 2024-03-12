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
struct stable
{
    static const int K = 20;
    vector<array<int, K>> f;
    int si;
    void work(vector<int> &a) // 默认从0开始
    {
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
    int ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual int op(const int &x, const int &y)
    {
        return min(x, y);
    }
};
struct St : stable
{
    St()
    {
    }
    St(vector<int> &a)
    {

        si = a.size();
        f.resize(si);
        work(a);
    }
    int op(const int &x, const int &y)
    {
        return max(x, y);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m);
    fir(i, 1, n + 1) cin >> a[i];
    fir(i, 0, m) cin >> b[i];
    vector<vector<int>> all(n + 1);
    a[0] = 0x3f3f3f3f;
    St st(a);
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < m; i++)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (st.ask(mid, r) >= b[i])
                l = mid;
            else
                r = mid - 1;
        }
        all[l].push_back(b[i]);
    }
    for (auto c : all[0])
        cout << c << " ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
        for (auto c : all[i])
            cout << c << " ";
    }
    cout << endl;
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