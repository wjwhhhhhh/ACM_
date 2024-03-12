#include <bits/stdc++.h>
using namespace std;
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
const int N = 2e5 + 10;
int a[N];
int n;
int st[N];
int Max()
{
    memset(st, 0, 4 * (n + 5));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < n + 1)
            st[a[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (!st[i])
            return i;
    }
    return n + 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int x = Max();
        if (x == n)
        {
            cout << "No"
                 << "\n";
            continue;
        }
        int l = 0x3f3f3f3f, r = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == x + 1)
                l = min(l, i), r = i;
        }
        // cerr<<l<<" "<<r;

        if (l == 0x3f3f3f3f)
        {
            bool fl = false;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] > x)
                {
                    fl = true;
                    a[i] = x;
                    break;
                }
            }
            if (!fl)
            {
                int who = -1;
                for (int i = 0; i <= x; i++)
                {
                    if (st[i] > 1)
                        who = i;
                }
                if (who != -1)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        if (a[i] == who)
                        {
                            a[i] = x;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = l; i <= r; i++)
                a[i] = n + 2;
            int y = Max();
            if (y == x + 1)
            {
                cout << "Yes" << '\n';
                continue;
            }
            else
            {
                for (int i = l; i <= r; i++)
                    a[i] = y;
            }
        }
        int y = Max();
        if (x + 1 == y)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}