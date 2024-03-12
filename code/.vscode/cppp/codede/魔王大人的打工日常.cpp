#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = 1;
    while (t--)
    {
        int n = read(), m = read();
        bool fl = true;
        fir(i, 1, m)
        {
            int l = read(), r = read(), k = read();
            int len = r - l + 1;
            k = k % len;
            len = (len - k) * k;
            if (len & 1)
                fl = !fl;
            if (fl)
                puts("hao");
            else
                puts("huai");
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}