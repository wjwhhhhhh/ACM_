#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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
set<int> ch;
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        ch.clear();
        int n = read(), m = read();
        fir(i, 1, n)
        {
            int tem = read();
            ch.insert(tem);
        }
        fir(i, 1, m)
        {
            double a = read(), b = read(), c = read();
            if (c <= 0)
                puts("NO");
            else
            {
                double re = b - 2.0 * sqrt(a) * sqrt(c);
                double re2 = b + 2 * sqrt(a) * sqrt(c);
                int re3, re4;
                if ((int)re == re)
                    re4 = (int)re + 1;
                else if (re < 0)
                    re4 = (int)re;
                else
                    re4 = (int)re + 1;
                if ((int)re2 == re2)
                    re3 = (int)re2 - 1;
                else if (re2 < 0)
                    re3 = (int)re2 - 1;
                else
                    re3 = (int)re2;
                auto w = ch.lower_bound(re4);
                if (w != ch.end() && *w <= re3)
                {
                    puts("YES");
                    cout << *w << endl;
                }
                else
                    puts("NO");
            }
        }
        puts("");
    }
    return 0;
}