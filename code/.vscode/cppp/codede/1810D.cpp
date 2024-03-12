#include <algorithm>
#include <cstring>
#include <iostream>
#define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
__int128 read()
{
    __int128 f = 1, w = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        w = w * 10 + ch - '0';
        ch = getchar();
    }
    return f * w;
}
void print(__int128 x)
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read();
        int l = 0, r = 0x3f3f3f3f3f3f3f3f;
        fir(i, 1, n)
        {
            int fl, a, b, tt, x, y;
            fl = read();
            if (fl == 1)
            {
                a = read(), b = read(), tt = read();
                if (tt == 1)
                    x = 0, y = a;
                else
                    x = (a - b) * (tt - 2) + a + 1, y = (a - b) * (tt - 1) + a;
                if ((l <= x && x <= r) || (l <= y && y <= r))
                {
                    cout << "1 ";
                    l = max(l, x), r = min(r, y);
                }
                else
                {
                    cout << "0 ";
                }
            }
            else
            {
                a = read(), b = read();
                if (r == 0x3f3f3f3f3f3f3f3f)
                    cout << "-1 ";
                else
                {
                    if (l <= a)
                        x = 1;
                    else
                    {
                        int tl = 2, tr = 0x3f3f3f3f3f3f3f3f;
                        while (tl < tr)
                        {
                            int mid = tl + tr >> 1;
                            if ((mid - 1) * (a - b) + a >= l)
                                tr = mid;
                            else
                                tl = mid + 1;
                        }
                        x = tl;
                    }
                    if ((x - 1) * (a - b) + a >= r)
                        print(x);
                    else
                        cout << "-1";
                    cout << " ";
                }
            }
        }
        puts("");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}