#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
struct Matrix
{
    i64 W = 10, M;
    vector<vector<ui64>> A, B;
    Matrix(i64 n, i64 m = 0)
    {
        A = std::vector(n, std::vector<ui64>(n, 0));
        B = std::vector(n, std::vector<ui64>(n, 0));
        M = m, W = n;
    }
    void mul(vector<vector<ui64>> &ans, vector<vector<ui64>> A, vector<vector<ui64>> B)
    {
        for (int i = 0; i < W; i++)
            fill(ans[i].begin(), ans[i].end(), 0);
        for (int i = 0; i < W; i++)
            for (int j = 0; j < W; j++)
                for (int k = 0; k < W; k++)
                {
                    ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]);
                }
    }
    void qmi(long long q)
    {
        while (q)
        {
            if (q & 1)
                mul(A, A, B);
            mul(B, B, B);
            q >>= 1;
        }
    }
    ui64 ask(int l, int r = -1)
    {
        if (r == -1)
            r = W - 1;
        i64 ans = 0;
        for (int i = l; i <= r; i++)
        {
            ans = (ans + A[0][i]);
        }
        return ans;
    }
};
struct AC
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
    void insert(string s, int id = 1) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];         // 搜索下一个节点
        }
        idx[u] = id; //
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
void solve(int n, int l)
{
    AC ac(30);
    Matrix ma(30), mb(30);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        ac.insert(a);
    }
    ac.build();
    mb.A[0][0] = ma.A[0][0] = 1;
    auto check = [&](int u) {
        while (u)
        {
            if (ac.idx[u])
                return false;
            u = ac.fail[u];
        }
        return true;
    };
    for (int i = 0; i <= ac.tot; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (check(ac.tr[i][j]))
                ma.B[i][ac.tr[i][j]]++;
        }
    }
    for (int i = 0; i <= ac.tot; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            mb.B[i][ac.tr[i][j]]++;
        }
    }
    for (int i = 0; i <= ac.tot + 1; i++)
        mb.B[i][ac.tot + 1] = ma.B[i][ac.tot + 1] = 1;
    // for (int i = 0; i <= ac.tot + 1; i++)
    // {
    //     for (int j = 0; j <= ac.tot + 1; j++)
    //         cout << mb.B[i][j] << " ";
    //     cout << endl;
    // }
    ma.qmi(l), mb.qmi(l);
    cout << mb.ask(0) - ma.ask(0) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    // cout << 27 + 26 * 26 + 26 * 26 * 26 << endl;
    while (cin >> n >> l)
    {
        solve(n, l);
    }
    return 0;
}