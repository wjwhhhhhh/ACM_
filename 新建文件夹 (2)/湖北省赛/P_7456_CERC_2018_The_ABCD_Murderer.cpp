#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int N = 4e5 + 100;
struct AC
{
    queue<int> q;
    vector<array<int, 26>> tr;
    int tot;
    vector<int> val, fail, idx; // val 每个节点经历的次数，idx自己用的,in入度
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
        tr.resize(n), idx.resize(n), fail.resize(n), val.resize(n);
    }
    int insert(string s, int id = 1) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
            {
                tr[u][s[i] - 'a'] = ++tot;
                val[tot] = val[u] + 1;
            };                     // 如果没有则插入新节点
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
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    AC ac(N);
    for (int i = 1; i <= n; i++)
    {
        string a;
        cin >> a;
        ac.insert(a, i);
    }
    ac.build();
    int ing = 0;
    vector<int> id(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        ing = ac.tr[ing][s[i] - 'a'];
        id[i] = ing;
    }
    vector<vector<int>> edge(ac.tot + 1);
    for (int i = 1; i <= ac.tot; i++)
    {
        edge[ac.fail[i]].push_back(i);
    }
    vector<int> w(ac.tot + 1);
    function<void(int)> dfs = [&](int u) {
        for (auto c : edge[u])
        {
            w[c] = w[u];
            if (ac.idx[c])
            {
                w[c] = max(w[c], ac.val[c]);
            }
            dfs(c);
        }
    };
    dfs(0);
    vector<vector<int>> mp(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
    {
        if (w[id[i]])
        {
            mp[i - w[id[i]] + 1].push_back(i);
        }
    }
    priority_queue<int> shh;
    int ling = 0, ans = 0;
    auto get = [&](int idx) {
        for (auto c : mp[idx])
            shh.push(c);
    };
    get(ling);
    while (ling < s.size())
    {
        if (shh.size() == 0 || ling > shh.top())
        {
            cout << "-1";
            return 0;
        }
        int tem = shh.top();
        ans++;
        do
        {
            ling++;
            get(ling);
        } while (ling < tem + 1);
    }
    cout << ans << endl;
    return 0;
}