#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
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
int w[N];
bool st[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    fir(i, 1, n) cin >> a[i];
    w[1] = 1;
    int l = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= a[i - 1])
            l++;
        else
            l = 0;
        if (l >= 2)
            w[i] = w[i - 1], st[i] = true;
        else
            w[i] = w[i - 1] + 1;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int tem = w[b] - w[a - 1];
        for (int i = a, j = 0; i <= b && j < 2; i++, j++)
            if (st[i])
                tem++;
        cout << tem << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}