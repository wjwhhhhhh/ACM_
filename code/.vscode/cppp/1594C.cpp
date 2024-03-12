#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
// #define int long long
// #define int __int128
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read();
        char ch;
        string tem;
        cin >> ch >> tem;
        int m = tem.size();
        tem = " " + tem;

        bool fl = true;
        for (int i = 1; i <= m; i++)
            if (tem[i] != ch)
                fl = false;
        if (fl)
        {
            puts("0");
            continue;
        }
        int res = -1;
        fir(i, m / 2 + 1, m) if (tem[i] == ch)
        {
            res = i;
        }
        if (res == -1)
        {
            cout << 2 << '\n';
            cout << m - 1 << " " << m;
        }
        else
        {
            cout << 1 << '\n';
            cout << res;
        }
        puts("");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}