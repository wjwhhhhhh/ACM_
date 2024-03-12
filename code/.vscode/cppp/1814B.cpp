#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
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
int a, b;
int shang(int x, int y)
{
    if (x % y == 0)
        return x / y;
    else
        return x / y + 1;
}

signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        a = read(), b = read();
        if (a > b)
            swap(b, a);
        int l = 1, sum = 0x3f3f3f3f;
        while (l <= 5e5)
        {
            int res = l - 1 + b / l + shang(b % l, l) + a / l + shang(a % l, l);
            sum = min(sum, res);
            l++;
        }
        cout << sum << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}