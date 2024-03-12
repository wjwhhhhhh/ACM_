#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    } // 是符号
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    } // 是数字
    return x * s;
}
void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
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
    void insert(string s, int id) // id也是题目要用的
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];         // 搜索下一个节点
        }
        idx[id] = u; //
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
    void topology()
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
const int N = 2e5 + 10;
string cnt[N];
map<string, int> cn;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    AC tt(N);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;

    fir(i, 1, t)
    {
        cin >> cnt[i];
        if (cn.find(cnt[i]) != cn.end())
            continue;
        cn.insert({cnt[i], i});
        tt.insert(cnt[i], i);
    }
    tt.build();
    string ans;
    cin >> ans;
    tt.query(ans);
    fir(i, 1, t)
    {
        cout << tt.val[tt.idx[cn[cnt[i]]]] << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}