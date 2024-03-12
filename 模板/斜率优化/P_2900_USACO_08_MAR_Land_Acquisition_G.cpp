#include <bits/stdc++.h>
#define int long long
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
const int N = 5e4 + 10;
std::vector<PII> at(N), bt(N);
std::vector<int> q(N), f(N);
int hh = 0, tt = 0;
int get_y(int a)
{
    return f[a];
}
int get_x(int a)
{
    return -bt[a + 1].first;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> at[i].first >> at[i].second;
    sort(at.begin() + 1, at.begin() + 1 + n);
    int l = 0;
    for (int i = n; i > 0; i--)
    {
        if (l == 0 || at[i].second > bt[l].second)
            bt[++l] = at[i];
    }
    n = l;
    q[hh] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = bt[i].second;
        while (hh < tt && get_y(q[hh + 1]) - get_y(q[hh]) <= k * (get_x(q[hh + 1]) - get_x(q[hh])))
            hh++;
        int j = q[hh];
        f[i] = f[j] + bt[i].second * bt[j + 1].first;
        while (hh < tt && (get_y(q[tt]) - get_y(q[tt - 1])) * (get_x(i) - get_x(q[tt])) >=
                              (get_y(i) - get_y(q[tt])) * (get_x(q[tt]) - get_x(q[tt - 1])))
            tt--;
        q[++tt] = i;
    }
    std::cout << f[n];
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}