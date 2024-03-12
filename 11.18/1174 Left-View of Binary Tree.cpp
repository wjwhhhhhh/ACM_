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
    vector<int> a(n), b(n);
    map<int, int> mp;
    int idx = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], mp[a[i]] = ++idx;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> cnt(a);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
        b[i] = mp[b[i]];
    vector<vector<int>> gra(n + 1);
    function<void(vector<int>, vector<int>, int)> sol = [&](vector<int> a, vector<int> b, int fa) {
        if (a.size() == 0 || b.size() == 0)
            return;
        gra[fa].push_back(b[0]);
        vector<int> ta, tb;
        for (auto c : a)
        {
            if (c == b[0])
                break;
            ta.push_back(c);
        }
        for (int i = 1; i < b.size() && tb.size() < ta.size(); i++)
        {
            tb.push_back(b[i]);
        }
        sol(ta, tb, b[0]);
        vector<int> at, bt;
        for (int i = ta.size() + 1; i < a.size() && i < b.size(); i++)
            at.push_back(a[i]), bt.push_back(b[i]);
        sol(at, bt, b[0]);
    };
    sol(a, b, 0);
    vector<int> dep(n + 1, -1), de(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto c : gra[u])
        {
            if (c == fa)
                continue;
            de[c] = de[u] + 1;
            if (dep[de[c]] == -1)
                dep[de[c]] = c;
            dfs(c, u);
        }
    };
    dfs(0, -1);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] == -1)
            break;
        ans.push_back(dep[i]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << cnt[ans[i] - 1] << " \n"[i + 1 == ans.size()];
    }
    return 0;
}