#include <algorithm>
#include <cstring>
#include <iostream>
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
        int n = read(), m = read();
        if (m == 0)
        {
            puts("2");
            cout << "1 1\n";
            cout << n << " " << 0 << '\n';
        }
        else if (n == 0)
        {
            puts("2");
            cout << "1 1\n";
            cout << 0 << " " << m << '\n';
        }
        else
        {
            puts("2");
            cout << n - 1 << ' ' << 1 << '\n';
            cout << n << " " << m << '\n';
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}