#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
// #define int long long
// #define int __int128
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
const int N = 110;
int g[N][N];
int st[N];
int dist[N];
int l, r;
int n, k;
queue<int> q;
void bfs()
{
    dist[l] = 0;
    q.push(l);
    st[l] = true;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!st[i] && g[t][i] == 1)
            {
                if (i == 1)
                    dist[i] = dist[t] + 1;
                q.push(i);
                st[i] = true;
            }
        }
    }
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    n = read(), k = read();
    fir(i, 0, n - 1) fir(j, 0, n - 1) cin >> g[i][j];
    int t;
    cin >> t;
    while (t--)
    {
        memset(st, 0, sizeof st);
        met(dist, 0x3f);
        cin >> l >> r;
        if (l == r)
        {
            puts("0");
            continue;
        }
        l--, r--;
        bfs();
        if (dist[r] == 0x3f3f3f3f)
            puts("-1");
        else
            cout << dist[r] << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}