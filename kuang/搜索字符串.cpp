#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct AC
{
    queue<int> q;
    vector<array<int, 26>> tr;
    int tot;
    vector<int> val, fail, idx, in, ans, has; // val 每个节点经历的次数，idx自己用的,in入度
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
        tr.resize(n), idx.resize(n), fail.resize(n), val.resize(n), in.resize(n), ans.resize(n), has.resize(n);
    }
    void insert(string s, int id = 1, bool fl) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];         // 搜索下一个节点
        }
        idx[u] = id;
        has[u] = fl; //
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
        }
    }
};
const int N = 6e5 + 10;
void solve(string &a)
{
    int n;
    cin >> n;
    AC ac(N);
    vector<int> len(n);
    for (int i = 0; i < n; i++)
    {
        int flag;
        string a;
        cin >> flag >> a;
        len[i] = a.size();
        ac.insert(a, i + 1, flag);
    }
    vector<int> cnt(n);
    vector<int> last(ac.tot, -0x3f3f3f3f);
    int u;
    for (int i = 0; i < a.size(); i++)
    {
        u = ac.tr[u][a[i] - 'a'];
        int j = u;
        while (j)
        {
            if (ac.idx[j])
            {
                int id = ac.idx[j] - 1;
                if (ac.has[j])
                {
                    if (i - last[j] >= len[id])
                        cnt[id]++, last[id] = i;
                }
                else
                    cnt[id]++;
            }
            j = ac.fail[j];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    string a;
    int si = 1;
    while (cin >> a)
    {
        cout << "Case " << si << endl;
        solve(a);
        si++;
    }
    return 0;
}