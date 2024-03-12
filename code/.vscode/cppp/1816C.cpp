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
const int N = 3e5 + 10;
int a[N];
int n;
bool check(int l)
{
    if (n == l)
        return true;
    if (n - l == 1)
    {
        if (a[n - 1] <= a[n])
            return true;
        else
            return false;
    }
    if (a[l] <= a[l + 1])
    {
        a[l + 2] -= a[l + 1] - a[l];
    }
    else
    {
        a[l + 2] += a[l] - a[l + 1];
    }
    if (check(l + 2))
        return true;
    else
        return false;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        n = read();
        bool fl;
        fir(i, 1, n) a[i] = read();
        fl = check(1);
        if (fl)
            puts("YES");
        else
            puts("NO");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}