#include <bits/stdc++.h>
const int bug = false;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
using namespace std;
using i64 = long long;
template <class T> struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n = 0)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n = a.size();
        init(n + 1);
        for (int i = 1; i < n; i++)
            insert(i, a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(T &x, T c)
    {
        x += c;
    }
};
struct Two_dimensional
{
    Tree_array<int> tr;
    int W; // 值域
    vector<array<int, 2>> w, q;
    Two_dimensional(int _w = 0, int _n = 0, int _m = 0)
    {
        init(_w, _n, _m);
    }
    void init(int _w, int _n, int _m)
    {
        W = _w;
        tr.init(_w);
        w.resize(_n), q.resize(_m);
    }
    bool cmp(const array<int, 2> &a, const array<int, 2> &b)
    {
        return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
    void sor(vector<int> &o, const vector<array<int, 2>> &a)
    {
        iota(o.begin(), o.end(), 0);
        sort(o.rbegin(), o.rend(), [&](const int x, const int y) { return cmp(a[x], a[y]); });
    }
    vector<int> query()
    {
        vector<int> ans(q.size());
        vector<int> o1(w.size()), o2(q.size());
        sor(o1, w);
        sor(o2, q);
        int idx = 0;
        fir(i, 0, q.size())
        {
            int id = o2[i];
            while (idx < w.size() && !cmp(w[o1[idx]], q[id]))
            {
                tr.insert(w[o1[idx]][1], 1);
                idx++;
            }
            ans[id] = tr.ask(q[id][1]);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> w(n);
    vector<array<int, 4>> q(m);
    fir(i, 0, n) fir(j, 0, 2) cin >> w[i][j], w[i][j]++;
    fir(i, 0, m) fir(j, 0, 4) cin >> q[i][j], q[i][j]++;
    set<array<int, 2>> all;
    fir(i, 0, m)
    {
        all.insert({q[i][2], q[i][3]});
        all.insert({q[i][0] - 1, q[i][1] - 1});
        all.insert({q[i][0] - 1, q[i][3]});
        all.insert({q[i][2], q[i][1] - 1});
    }
    Two_dimensional tw(1e7 + 10, n, all.size());
    tw.w = w;
    int idx = 0;
    for (auto a : all)
    {
        tw.q[idx++] = a;
    }
    auto ans = tw.query();
    unordered_map<array<int, 2>, int> mp;
    fir(i, 0, all.size())
    {
        mp[tw.q[i]] = ans[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << mp[{q[i][2], q[i][3]}] + mp[{q[i][0] - 1, q[i][1] - 1}] - mp[{q[i][0] - 1, q[i][3]}] -
                    mp[{q[i][2], q[i][1] - 1}]
             << '\n';
    }
    return 0;
}