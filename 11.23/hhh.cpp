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
        x |= c;
    }
};
const int N = 2e5 + 10;
vector<vector<int>> que(N);
vector<vector<two>> ask(N);
struct AC // 记得build()!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!
{
    queue<int> q;
    vector<array<int, 26>> tr;
    int tot;
    vector<int> val, fail, idx, in, len; // val 每个节点经历的次数，idx自己用的,in入度
    AC()
    {
    }
    AC(int n)
    {
        init(n);
    }
    void init(int n) // 字母个数
    {
        tot = 0;
        tr.resize(n), idx.resize(n), fail.resize(n), val.resize(n, 0x3f3f3f3f), len.resize(n);
    }
    int insert(string s, int id = 1) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot;
            // 如果没有则插入新节点
            len[tr[u][s[i] - 'a']] = len[u] + 1;
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
                    q.push(tr[u][i]);
                }
                else
                    tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    void work()
    {
        vector<vector<int>> edge(tot + 1);
        for (int i = 1; i <= tot; i++)
        {
            edge[fail[i]].push_back(i);
        }
        function<void(int)> dfs = [&](int u) {
            if (idx[u])
                chmin(val[u], len[u]);
            for (auto c : edge[u])
            {
                if (val[u] != 0x3f3f3f3f)
                    chmin(val[c], val[u]);
                dfs(c);
            }
        };
        // cout << val[0] << endl;
        dfs(0);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    AC ac(N);
    for (int i = 0; i < n; i++)
    {
        ac.insert(a[i], i + 1);
    }
    // dug("ok");
    ac.build();
    ac.work();
    string t;
    cin >> t;
    t = " " + t;
    // cout << ac.val[0] << endl;
    int u = 0;
    for (int i = 1; i < t.size(); i++)
    {
        u = ac.tr[u][t[i] - 'a'];
        // cout << u << endl;
        if (ac.val[u] != 0x3f3f3f3f)
        {
            // cout << ac.len[u] << endl;
            // cout << i - ac.val[u] + 1 << " " << i << endl;
            que[i - ac.val[u] + 1].push_back(i);
        }
    }
    int q;
    cin >> q;
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        ask[x].push_back(two{y, i});
    }
    Tree_array<int> tr(N);
    for (int i = N - 1; i > 0; i--)
    {
        for (auto x : que[i])
            tr.insert(x, 1);
        for (auto [x, y] : ask[i])
            ans[y] = tr.ask(x);
    }
    for (int i = 0; i < q; i++)
    {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
    return 0;
}