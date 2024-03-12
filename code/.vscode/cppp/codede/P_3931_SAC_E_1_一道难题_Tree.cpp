#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int h[N], w[M], ne[M], e[M], idx = 0;
LL flow[N], last[N];
set<int> ct;
int n, s, p;
typedef pair<int, int> PII;
void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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
void dfs(int u, int fa)
{
    // cout << u;
    int s = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            w[i ^ 1] = 0;
            // cout << (i ^ 1) << " ";
            dfs(j, u);
            s++;
        }
    }
    if (s == 0)
        ct.insert(u);
}
/* LL dfs2(int p, LL flow)
{
    // cout << p << endl;
    v[p] = true;
    if (ct.find(p) != ct.end())
    {

        return flow;
    }
    for (int i = h[p]; ~i; i = ne[i])
    {
        int j = e[i];
        LL we = w[i], c;

        if (we > 0 && !v[j] && (c = dfs2(j, min(flow, we))) != -1)
        {

            w[i] -= c, w[i ^ 1] += c;
            return c;
        }
    }
    return -1;
}
LL FF()
{
    LL ans = 0, c;
    while ((c = dfs2(s, 0x3f3f3f3f)) != -1)
    {
        memset(v, 0, sizeof v);
        ans += c;
    }
    return ans;
} */
bool bfs()
{
    memset(last, -1, sizeof last);
    queue<int> q;
    q.push(s);
    flow[s] = 0x3f3f3f3f3f3f3f3f;
    while (q.size())
    {
        cout << p << " ";
        p = q.front();
        q.pop();
        if (ct.find(p) != ct.end())
        {
            break;
        }
        for (int i = h[p]; ~i; i = ne[i])
        {
            int j = e[i];
            LL we = w[i];
            if (we > 0 && last[j] == -1)
            {
                last[j] = i;
                flow[j] = min(flow[p], we);
                q.push(j);
            }
        }
    }
    return last[p] != -1;
}
long long EK()
{
    LL maxflow = 0;
    while (bfs())
    {
        maxflow += flow[p];
        for (int i = p; i != s; i = e[last[i] ^ 1])
        {
            w[last[i]] -= flow[p];
            w[last[i] ^ 1] += flow[p];
        }
    }
    return maxflow;
}
int main()
{
    memset(h, -1, sizeof h);
    // freopen("test.txt", "r", stdin);
    n = read(), s = read();
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(s, -1);
    // cout << idx;
    //  cout << w[10];
    //   FF();
    cout << EK();
    //     freopen("CON", "r", stdin);
    system("pause");
    return 0;
}