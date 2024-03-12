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
    vector<int> e, fail;
    AC()
    {
    }
    AC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        tot=0;
        tr.resize(n), e.resize(n), fail.resize(n);
    }
    void insert(string s)
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];         // 搜索下一个节点
        }
        e[u]++; // 尾为节点 u 的串的个数
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

    int query(string t)
    {
        int u = 0, res = 0;
        for (int i = 0; i < t.size(); i++)
        {
            u = tr[u][t[i] - 'a']; // 转移
            for (int j = u; j && e[j] != -1; j = fail[j])
            {
                res += e[j], e[j] = -1;
            }
        }
        return res;
    }
};
const int N = 1e6 + 10;
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
        string tem;
        cin >> tem;
        tt.insert(tem);
    }
    tt.build();
    string ans;
    cin >> ans;
    cout << tt.query(ans) << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}