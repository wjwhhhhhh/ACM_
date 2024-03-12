#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
bool op(char a, char b)
{
    return a == b;
}
int n;
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
        tr.resize(n), idx.resize(n), fail.resize(n);
    }
    int insert(string s, int id = 1) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];         // 搜索下一个节点
        }
        idx[u] |= 1 << id; //
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
    void query()
    {
        vector<vector<int>> edge(tot + 1);
        for (int i = 1; i <= tot; i++)
            edge[fail[i]].push_back(i);
        function<void(int)> dfs = [&](int u) {
            for (auto c : edge[u])
            {
                idx[c] |= idx[u];
                dfs(c);
            }
        };
        dfs(0);
        vector<vector<int>> st(tot + 1, vector<int>(1 << n));
        vector<vector<array<int, 2>>> fr(tot + 1, vector<array<int, 2>>(1 << n));
        vector<vector<char>> ch(tot + 1, vector<char>(1 << n));
        queue<array<int, 2>> qq;
        qq.push({0, 0});
        st[0][0] = true;
        string ans;
        while (qq.size())
        {
            auto [x, y] = qq.front();
            qq.pop();
            if (y == (1 << n) - 1)
            {
                while (x != 0 && y != 0)
                {
                    ans += ch[x][y];
                    x = fr[x][y][0], y = fr[x][y][1];
                }
                reverse(ans.begin(), ans.end());
                cout << ans << endl;
                return;
            }
            int si = 0;
            for (int i = 0; i < 26; i++)
            {
                if (tr[x][i] != 0)
                {
                    if (!st[tr[x][i]][y | idx[tr[x][i]]])
                    {
                        si++;
                        fr[tr[x][i]][y | idx[tr[x][i]]] = {x, y};
                        ch[tr[x][i]][y | idx[tr[x][i]]] = char('A' + i);
                        qq.push({tr[x][i], y | idx[tr[x][i]]});
                        st[tr[x][i]][y | idx[tr[x][i]]] = true;
                    }
                }
            }
            if (si == 0 && !st[tr[x][0]][y | idx[tr[x][0]]])
            {
                fr[tr[x][0]][y | idx[tr[x][0]]] = {x, y};
                ch[tr[x][0]][y | idx[tr[x][0]]] = char('A' + 0);
                qq.push({tr[x][0], y | idx[tr[x][0]]});
                st[tr[x][0]][y | idx[tr[x][0]]] = true;
            }
        }
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    cin >> n;
    vector<string> all(n);
    for (int i = 0; i < n; i++)
        cin >> all[i];
    AC ac(610);
    for (int i = 0; i < n; i++)
        ac.insert(all[i], i);
    ac.build();
    ac.query();
    return 0;
}