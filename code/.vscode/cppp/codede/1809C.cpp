#include <algorithm>
#include <cstring>
#include <iostream>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
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
int f[40];
int main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int res = 0, l = n;
        while (res < k)
        {
            res += l--;
        }
        res = k - (res - l - 1) - 1;
        l = n - l;
        for (int i = 1; i < l; i++)
            f[i] = 1000;
        f[l] = res + 1;
        int i, j;
        for (i = l + 1, j = 0; j < res; i++, j++)
        {
            f[i] = -1;
        }
        for (; i <= n; i++)
            f[i] = -31;
        for (int i = 1; i <= n; i++)
            cout << f[i] << " ";
        puts("");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}