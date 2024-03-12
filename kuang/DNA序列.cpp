#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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
            if (!tr[u][s[i] - 'A'])
                tr[u][s[i] - 'A'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'A'];         // 搜索下一个节点
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
const int W = 110, M = 1e5;
long long A[W][W] = {
    0,
};
long long B[W][W] = {
    0,
};
void mul(long long ans[W][W], long long A[W][W], long long B[W][W])
{
    long long tem[W][W] = {0};
    for (int i = 0; i < W; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < W; k++)
            {
                tem[i][j] = (tem[i][j] + A[i][k] * B[k][j]) % M;
            }
    memcpy(ans, tem, sizeof tem);
}
long long qmi(long long q)
{
    long long res = 0;
    while (q)
    {
        if (q & 1)
            mul(A, A, B);
        mul(B, B, B);
        q >>= 1;
    }
    return res;
}
AC ac(W);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        ac.insert(a);
    }
    ac.build();
    string te = "ACTG";
    A[0][0] = 1;
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
        for (auto j : te)
        {
            if (check(ac.tr[i][j - 'A']))
                B[i][ac.tr[i][j - 'A']]++;
        }
    }
    qmi(m);
    i64 ans = 0;
    for (int i = 0; i <= ac.tot; i++)
        if (!ac.idx[i])
            ans = (ans + A[0][i]) % M;
    cout << ans << endl;
    return 0;
}