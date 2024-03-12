#include <bits/stdc++.h>
using namespace std;
#define int long long
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

const int N = 3e5 + 10;
map<int, int> mi, st;
int ma[N];
int a[N], b[N];
int l = -1;
void in(int x)
{
    if (mi.find(x) == mi.end())
        mi[x] = ++l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);

    int n, k, ans = 0;
    cin >> n >> k;
    fir(i, 1, n) cin >> a[i];
    fir(i, 1, n) cin >> b[i];
    fir(i, 1, n)
    {
        in(a[i]);
        int t = mi[a[i]];
        ans = max(ans, b[i]);
        st[b[i]] = i;
        ma[t] = max(ma[t], b[i]);
    }
    if (mi.find(k) == mi.end())
    {
        k = mi[a[1]];
    }

    int t = mi[k];
    cout << st[ma[t]] << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}