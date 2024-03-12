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
const int N = 1e5 + 10;
int p[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

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
    int m = read(), n = read();
    fir(i, 1, n) p[x] = i;
    fir(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            p[find(b)] = find(c);
        }
        else
        {
            if (find(b) == find(c))
                puts("YES");
            else
                puts("NO");
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}