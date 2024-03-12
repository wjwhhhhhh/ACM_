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
int a[N], b[N];
int n;
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
        fir(i, 1, n) cin >> a[i];
        fir(i, 1, n) cin >> b[i];
        int l = 1;
        while (l <= n && a[l] == b[l])
            l++;
        // cout << l;
        if (l > n)
        {
            cout << "1 " << n << endl;
            continue;
        }
        int r = n;
        while (r > 0 && a[r] == b[r])
            r--;
        // cout << l << ' ' << r << endl;
        while (l > 1 && b[l - 1] <= b[l])
            l--;
        while (r < n && b[r] <= b[r + 1])
            r++;
        cout << l << ' ' << r << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}