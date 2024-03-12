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
const int N = 110;
int d[N];
int ans[N];
struct edge
{
    int x, y;
} tr[N];
bool v[N];
bool fl;
vector<vector<int>> a;
int n, m;
void dfs(int wei)
{
    if (wei == n)
    {
        if (ans[n] == d[n])
            fl = true;
        return;
    }
    if (ans[wei] >= d[wei])
    {
        dfs(wei + 1);
        return;
    }
    for (auto i : a[wei])
    {
        // if(tr[i].x!=wei)swap(tr[i].x,tr[i].y);
        if (!v[i])
        {
            v[i] = true;
            ans[tr[i].x]++, ans[tr[i].y]++;
            dfs(wei);
            ans[tr[i].x]--, ans[tr[i].y]--;
            v[i] = false;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);

    while (cin >> n >> m)
    {
        fl = false;
        a.clear();
        a.resize(N);
        fir(i, 1, n) cin >> d[i];
        met(ans, 0);
        met(v, 0);
        fir(i, 1, m)
        {
            int tr1, tr2;
            cin >> tr1 >> tr2;
            a[tr1].push_back(i), a[tr2].push_back(i);
            tr[i].x = tr1, tr[i].y = tr2;
        }
        dfs(1);
        if (fl)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}