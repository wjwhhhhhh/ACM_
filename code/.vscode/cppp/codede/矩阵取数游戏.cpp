#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define int __int128
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
int a[110];
int n, m;
int tan()
{
    int res = 0;
    int tem = 1;
    for (int k = 1, i = 0, j = m; k <= m; k++)
    {
        if (a[i] < a[j])
            res += (tem << k) * a[i], i++;
        else
            res += (tem << k) * a[j], j--;
    }
    return res;
}
signed main()
{
    // freopen("test.txt", "r", stdin);

    n = read(), m = read();
    int sum = 0;
    fir(i, 1, n)
    {
        fir(j, 1, m) a[j] = read();
        sum += tan();
    }
    cout << sum << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}