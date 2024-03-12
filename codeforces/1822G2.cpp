#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 2e5 + 10, M = 1e6, Q = 1e9;
int q[N], tt = -1;
int f[N];
LL sum = 0;
int te;
map<int, int> a;
void dfs(int wei, int ans)
{
    if (wei >= tt + 1)
    {
        // if (te == 2)
        //     cout << ans << endl;
        if (ans == 1)
            return;
        if (a.find(ans * te) == a.end() || a.find(te / ans) == a.end())
            return;
        sum += a[ans * te] * a[te] * a[te / ans];
        return;
    }
    int rt = 1;
    for (int i = 0; i <= f[wei]; i++)
    {
        dfs(wei + 1, rt * ans);
        rt *= q[wei];
    }
}
void solves()
{
    a.clear();
    int n;
    cin >> n;
    sum = 0;
    fir(i, 1, n)
    {
        int tem;
        cin >> tem;
        a[tem]++;
    }

    for (auto i : a)
    {
        sum += (i.second - 2) * i.second * (i.second - 1);
        if (i.first <= M)
        {
            tt = -1;
            te = i.first;
            int ch = te;
            for (int j = 2; j <= ch / j; j++)
            {
                if (ch % j == 0)
                {
                    q[++tt] = j, f[tt] = 0;
                    while (ch % j == 0)
                        f[tt]++, ch /= j;
                }
            }
            if (ch != 1)
            {
                q[++tt] = ch, f[tt] = 1;
            }
            dfs(0, 1);
        }
        else
        {
            te = i.first;
            for (int i = 2; i * te <= Q; i++)
            {
                if (te % i != 0 || a.find(i * te) == a.end() || a.find(te / i) == a.end())
                    continue;
                sum += a[i * te] * a[te] * a[te / i];
            }
        }
        // cout << sum << endl;
    }
    cout << sum << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}