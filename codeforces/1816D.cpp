#include <bits/stdc++.h>
// #define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
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
int ask(int a, int b)
{
    int tem;
    std::cout << "? " << a << " " << b << std::endl;
    std::cout << std::endl;
    std::cin >> tem;
    return tem;
}
const int N = 1e3 + 10;
std::vector<int> a(N), b(N), di(N), seq(N);
signed main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int ten;
        std::cout << "+ " << n << std::endl << std::endl;
        std::cin>>ten;
        std::cout << "+ " << n + 1 << std::endl << std::endl;
        std::cin>>ten;
        int who = 1, dist = 0;
        for (int i = 2; i <= n; i++)
        {
            int tem = ask(1, i);
            if (tem > dist)
                who = i, dist = tem;
        }
        for (int i = 1; i <= n; i++)
        {
            di[i] = (i == who ? 1 : ask(who, i) + 1);
        }
        int l = n, r = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                seq[i] = l--;
            else
                seq[i] = r++;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = seq[di[i]], b[i] = seq[n + 1 - di[i]];
        }
        std::cout << "! ";
        for (int i = 1; i <= n; i++)
            std::cout << a[i] << " ";
        for (int i = 1; i <= n; i++)
            std::cout << b[i] << " ";
        std::cout << std::endl << std::endl;
        std::cin>>ten;
    }
    return 0;
}