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
int n, m;
int check(int a, int b)
{
    if (b == 1 && (a == 1 || a == n))
        return 2;
    if (b == m && (a == 1 || a == n))
        return 2;
    if (a == 1 || a == n || b == 1 || b == m)
        return 3;
    return 4;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        n = read(), m = read();
        int a = read(), b = read(), c = read(), d = read();
        int l = 0x3f3f3f3f;
        l = min(l, check(a, b));
        l = min(l, check(c, d));
        cout << l << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}