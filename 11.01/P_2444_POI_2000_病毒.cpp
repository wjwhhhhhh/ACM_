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
struct AC // 记得build()!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!
{
    queue<int> q;
    vector<array<int, 26>> tr;
    int tot;
    vector<int> val, fail, idx, in, ans; // val 每个节点经历的次数，idx自己用的,in入度
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
        tr.resize(n), idx.resize(n), fail.resize(n), val.resize(n), in.resize(n), ans.resize(n);
    }
    int insert(string s, int id = 1) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - '0'])
                tr[u][s[i] - '0'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - '0'];         // 搜索下一个节点
        }
        idx[u] = id; //
        return u;
    }
    void build()
    {
        for (int i = 0; i < 2; i++)
            if (tr[0][i])
                q.push(tr[0][i]);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 2; i++)
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
    void topology() // 拓扑排序加速
    {
        for (int i = 0; i <= tot; ++i)
            if (in[i] == 0)
                q.push(i); // 将入度为0的点全部压入队列里
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] = ans[u]; // 如果有flag标记就更新vis数组
            int v = fail[u];
            in[v]--;          // 将唯一连出去的出边fail的入度减去（拓扑排序的操作）
            ans[v] += ans[u]; // 更新fail的ans值
            if (in[v] == 0)
                q.push(v); // 拓扑排序常规操作
        }
    }
    int query(string t)
    {
        int u = 0, res = 0;
        for (int i = 0; i < t.size(); i++)
        {
            u = tr[u][t[i] - 'a']; // 转移
            ans[u]++;
        }
        topology();
        return res;
    }
};
const int N = 3e4 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    AC ac(N);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        ac.insert(a, i + 1);
    }
    ac.build();
    vector<vector<int>> e(ac.tot + 1);
    for (int i = 1; i <= ac.tot; i++)
    {
        e[ac.fail[i]].push_back(i);
    }
    function<void(int, int)> dt = [&](int u, int res) {
        for (auto c : e[u])
        {
            ac.idx[c] |= ac.idx[u];
            dt(c, ac.idx[u]);
        }
    };
    dt(0, 1);
    vector<vector<int>> edge(ac.tot + 1);
    for (int i = 0; i <= ac.tot; i++)
    {
        if (ac.idx[i])
            continue;
        for (int j = 0; j < 2; j++)
        {
            edge[i].push_back(ac.tr[i][j]);
        }
    }
    vector<int> v(ac.tot + 1), in(ac.tot + 1);
    function<bool(int)> dfs = [&](int u) {
        in[u] = v[u] = true;
        for (auto c : edge[u])
        {
            if (in[c])
                return true;
            else if (!v[c] && dfs(c))
                return true;
        }
        in[u] = false;
        return false;
    };
    if (dfs(0))
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;
    return 0;
}