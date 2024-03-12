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
const int N = 5010;
int a[N], b[N], c[N];
int h[N];
int f[N];
vector<int> w[N];
bool vis[N];
priority_queue<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    fir(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        h[v] = max(h[v], u);
    }
    fir(i, 1, n)
    {
        w[i].push_back(i);
        if (h[i])
            w[h[i]].push_back(i);
    }
    for (int i = n; i > 0; i--)
    {
        f[i] = max(a[i], f[i + 1] - b[i]);
    }
    int ans = 0, sum = k;
    bool fl = true;
    for (int i = 1; i <= n && fl; i++)
    {
    
        if (sum < f[i])
            fl = false;
        else
        {
            auto cmp = [&](int x, int y) { return x > y; };
            sum += b[i];
            sort(w[i].begin(), w[i].end(), cmp);

            for (auto it : w[i])
            {
                if (vis[it])
                    continue;
                if (sum > f[i])
                {
                    sum--, ans += c[it];
                    st.push(-c[it]);
                    vis[it] = true;
                }
                else if(sum==f[i]&&c[it]>)
                {

                }
            }
        }
    }
    fir(i, 1, n) cout << f[i] << ' ';
    // if (!fl)
    //     puts("-1");
    // else
    //     cout << ans << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}