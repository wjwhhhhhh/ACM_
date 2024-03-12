#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Tree_array
{
    vector<int> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    void init(int n)
    {
        maxx = n;
        tr.assign(n + 1, 0);
    }
    void insert(int x, int c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(i, c);
    }
    int ask(int x)
    {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int x, int c)
    {
        tr[x] ^= c;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < 3; j++)
            v.push_back(a[i][j]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<int, int> li;
    int idx = 1;
    for (auto x : v)
        li[x] = idx++;

    Tree_array tr(idx);
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x][0] < a[y][0]; });
    for (int i = 0; i < n; i++)
    {
        vector<int> has;
        int l = 0;
        while (i + l < n && a[o[i]][0] == a[o[i + l]][0])
            has.push_back(o[i + l]);
    }
    return 0;
}