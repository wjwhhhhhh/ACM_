#pragma GCC optimize(3, "Ofast", "inline")
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
const int M = 20090717;
int dp[30][(1 << 11)][110]; // 长度，有几个，结尾
void solve(int n, int m, int k)
{
    memset(dp, 0, sizeof dp);
    AC ac(110);
    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        ac.insert(a, i + 1);
    }
    ac.build();
    vector<int> st(ac.tot + 1);
    for (int i = 0; i <= ac.tot; i++)
    {
        int u = i, an = 0;
        while (u)
        {
            if (ac.idx[u])
                an |= 1 << ac.idx[u] - 1;
            u = ac.fail[u];
        }
        st[i] = an;
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1 << m; j++)
        {
            for (int z = 0; z <= ac.tot; z++)
            {

                for (int ch = 0; ch < 26; ch++)
                {
                    int move = ac.tr[z][ch];
                    if (dp[i][j][z] == 0)
                        continue;
                    dp[i + 1][j | st[move]][move] = (dp[i + 1][j | st[move]][move] + dp[i][j][z]) % M;
                }
            }
        }
    }
    i64 ans = 0;
    auto check = [&](int x) {
        int si = 0;
        while (x)
        {
            if (x & 1)
                si++;
            x /= 2;
        }
        return si;
    };
    for (int z = 0; z <= ac.tot; z++)
        for (int j = 0; j < 1 << m; j++)
        {
            if (check(j) >= k)
                ans = (ans + dp[n][j][z]) % M;
        }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    while (cin >> n >> m >> k, n || m || k)
    {
        solve(n, m, k);
    }
    return 0;
}