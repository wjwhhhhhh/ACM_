#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
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

int main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        n = read();
        int x = 0, y = 0, z = 0;
        bool fl = false;
        for (int i = 0; i < n; i++)
        {
            a[i] = read();
            if (a[i] == 0)
                x++;
            else
            {
                y++;
                if (a[i] > 1)
                    fl = true;
                if (a[i] == 1)
                    z++;
            }
        }
        if (x <= y + 1)
            puts("0");
        else if (x == n)
            puts("1");
        else if (!fl)
        {
            puts("2");
        }
        else
            puts("1");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}