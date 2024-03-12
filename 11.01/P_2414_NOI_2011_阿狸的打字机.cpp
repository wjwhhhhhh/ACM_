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
const int N = 1e5 + 10;
struct AC // 记得build()!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!
{
    queue<int> q;
    vector<array<int, 26>> tr;
    int tot, u;
    vector<int> val, fail, idx, in, ans, fa; // val 每个节点经历的次数，idx自己用的,in入度
    AC()
    {
    }
    AC(int n)
    {
        init(n);
    }
    void init(int n) // 字母个数
    {
        u = 0;
        tot = 0;
        tr.resize(n), idx.resize(n), fail.resize(n), val.resize(n), in.resize(n), ans.resize(n);
        fa.resize(n);
    }
    int insert(string s, int id = 1) // id也是题目要用的
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
            {
                tr[u][s[i] - 'a'] = ++tot;
                fa[tot] = u;
            }                      // 如果没有则插入新节点
            u = tr[u][s[i] - 'a']; // 搜索下一个节点
        }
        idx[u] = id; //
        return u;
    }
    void build()
    {
        for (int i = 0; i < 26; i++)
            if (tr[0][i])
                q.push(tr[0][i]);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                if (tr[u][i])
                {
                    fail[tr[u][i]] = tr[fail[u]][i]; // fail数组：同一字符可以匹配的其他位置
                    in[fail[tr[u][i]]]++;
                    q.push(tr[u][i]);
                }
                else
                    tr[u][i] = tr[fail[u]][i];
            }
        }
    }
};
template <class T> struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
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
    virtual void op(T &x, T c)
    {
        x += c;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string p;
    cin >> p;
    AC ac(p.size());
    vector<int> id;
    int n = p.size();
    fir(i, 0, p.size())
    {
        if (p[i] == 'B')
            ac.u = ac.fa[ac.u];
        else if (p[i] == 'P')
        {
            id.push_back(ac.u);
        }
        else
        {
            string tem{p[i]};
            ac.insert(tem);
        }
    }
    ac.build();
    int t;
    cin >> t;
    using P2 = pair<int, int>;
    vector<vector<P2>> mp(id.size());
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mp[b].push_back({a, i});
    }
    vector<vector<int>> edg(ac.tot + 1);
    for (int i = 1; i <= ac.tot; i++)
    {
        edg[ac.fail[i]].push_back(i);
    }
    vector<int> df(ac.tot + 1), siz(ac.tot + 1);
    int time = 1;
    function<void(int)> dfs = [&](int u) {
        df[u] = time++;
        siz[u] = 1;
        for (auto c : edg[u])
        {
            dfs(c);
            siz[u] += siz[c];
        }
    };
    dfs(0);
    Tree_array<i64> tr(ac.tot + 1);
    vector<int> ans(t);
    ac.u = 0;
    int idx = 0;
    fir(i, 0, p.size())
    {
        if (p[i] == 'B')
        {
            tr.insert(df[ac.u], -1);
            ac.u = ac.fa[ac.u];
        }
        else if (p[i] == 'P')
        {
            id.push_back(ac.u);
            for (auto [x, zid] : mp[idx])
            {
                // cerr << ac.tot + 1 << endl;
                ans[zid] = tr.ask(df[id[x]] + siz[id[x]] - 1) - tr.ask(df[id[x]] - 1);
            }
            idx++;
        }
        else
        {
            string tem{p[i]};
            ac.insert(tem);
            // cerr << df[ac.u] << "ok" << endl;
            tr.insert(df[ac.u], 1);

            // cerr << tr.ask(ac.tot + 1) << endl;
        }
    }
    for (auto c : ans)
        cout << c << '\n';
    return 0;
}