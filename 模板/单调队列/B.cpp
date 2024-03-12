#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
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
const int N = 5e5 + 10;
int f[N], d1[N], d2[N], ff[N], dist[N];
vector<PII> cy;
bool v[N];
char tem[N];
int q[N];
int tt = 0, hh = 0;
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read(), k = read();
        scanf("%s", tem + 1);
        for (int i = 1; i <= n; i++)
            if (tem[i] == '1')
                v[i] = true;
        cy.clear();
        memset(f, 0, 4 * (n + 5)), memset(ff, 0, 4 * (n + 5));
        for (int i = 1; i <= n; i++)
            dist[i] = read();
        hh = tt = 0;
        q[0] = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            while (q[hh] + k < i)
                hh++;
            f[i] = f[q[hh]] + dist[i];
            if (v[i])
            {
                hh = tt = 0, q[0] = i;
            }
            else
            {
                while (hh <= tt && f[i] <= f[q[tt]])
                    tt--;
                q[++tt] = i;
            }
        }
        hh = tt = 0;
        q[0] = n + 1;
        for (int i = n; i >= 0; i--)
        {
            while (q[hh] - k < i)
                hh++;
            ff[i] = ff[q[hh]] + dist[i];
            if (v[i])
            {
                hh = tt = 0, q[0] = i;
            }
            else
            {
                while (hh <= tt && f[i] <= f[q[tt]])
                    tt--;
                q[++tt] = i;
            }
        }
        int p = read();
        while (p--)
        {
            int a = read(), b = read();
            int ans = f[a] + ff[a] + (b - dist[a]);
            if (v[a])
            {
                printf("%lld\n", ans);
                continue;
            }
            hh = 0, tt = -1;
            for (int i = a + 1; i <= n + 1 && i <= a - 1 + k; i++)
            {
                if (hh <= tt || (ff[q[tt]] > ff[i]))
                    q[++tt] = i;
                if (v[i])
                    break;
            }
            for (int i = a - 1; i >= 0 && i + k >= a + 1; i--)
            {
                while (q[tt] - k < i)
                    tt--;
                ans = min(ans, f[i] + ff[q[tt]]);
                if (v[i])
                    break;
            }
            printf("%lld\n", ans);
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}