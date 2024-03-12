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
struct string_hash
{
#define ull unsigned long long
    const int Q = 131;
    vector<ull> h, p;
    string_hash()
    {
    }
    string_hash(int n)
    {
        init(n);
    }
    void init(int n)
    {
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] * Q;
    }
    void Prefix_sum_Storage(string str)
    {
        int n = str.size();
        h.resize(n + 1);
        str = " " + str;
        for (int i = 1; i <= n; i++)
        {
            h[i] = h[i - 1] * Q + str[i];
        }
    }
    ull get_Prefix_sum(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    ull encode(string str)
    {
        ull res = 0;
        for (auto i : str)
        {
            res = res * Q + i;
        }
        return res;
    }
};
const int N = 1e6 + 10;
int sta[100], top;
bool f[20][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    string a;
    cin >> a;
    int t;
    cin >> t;
    string_hash ans(N);
    a = a + '?';
    ans.Prefix_sum_Storage(a);
    a = " " + a;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == '*' || a[i] == '?')
            sta[++top] = i;
    }
    while (t--)
    {
        string tem;
        cin >> tem;
        tem = tem + '#';
        string_hash anb(N);
        anb.Prefix_sum_Storage(tem);
        tem = " " + tem;
        met(f, 0), f[0][0] = 1;
        for (int i = 0; i < top; i++)
        {
            if (a[sta[i]] == '*')
            {
                for (int j = 1; j < tem.size(); j++)
                    f[i][j] |= f[i][j - 1];
            }
            for (int j = 0; j < tem.size(); j++)
            {
                if (!f[i][j])
                    continue;
                int l = sta[i] + 1, r = sta[i + 1] - 1, ls = j + 1, lr = ls + (r - l);
                if (ans.get_Prefix_sum(l, r) == anb.get_Prefix_sum(ls, lr))
                {
                    f[i + 1][lr + (a[sta[i + 1]] == '?')] |= f[i][j];
                }
            }
        }
        // cout << top;
        if (f[top][tem.size() - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    // cout << sta[0] << sta[1] << endl;
    //  freopen("CON", "r", stdin);
    //  system("pause");
    return 0;
}