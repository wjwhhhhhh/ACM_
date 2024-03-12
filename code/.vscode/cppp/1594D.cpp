#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
// #define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 2e5 + 10, M = 1e6 + 10;
int h[N], e[M], ne[M], idx = 1;
int p[N], color[N], si[N];
typedef long long LL;
typedef pair<int, int> PII;
int cnt, res;
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
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
vector<PII> st;
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
bool dfs(int root, int co)
{
    // cout << root;
    color[root] = co;
    cnt += si[root];
    if (co == 1)
        res += si[root];
    for (int i = h[root]; i; i = ne[i])
    {
        int j = e[i];
        if (color[j] == 0)
        {
            if (!dfs(j, 3 - co))
                return false;
        }
        else if (color[j] == color[root])
            return false;
        ;
    }
    return true;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        st.clear();
        int n = read(), m = read();
        fir(i, 1, n) p[i] = i, si[i] = 1;
        memset(h, 0, sizeof(int) * (n + 5));
        memset(color, 0, sizeof(int) * (n + 5));
        idx = 1;
        fir(i, 1, m)
        {
            int x, y;
            string tem;
            cin >> x >> y >> tem;
            if (tem == "crewmate")
            {
                if (find(x) != find(y))
                {
                    si[find(y)] += si[find(x)];
                    p[find(x)] = find(y);
                }
            }
            else
                st.push_back({x, y});
        }
        bool fl = true;
        for (auto ch : st)
        {
            if (find(ch.first) == find(ch.second))
            {
                fl = false;
                break;
            }
            add(find(ch.first), find(ch.second)), add(find(ch.second), find(ch.first));
        }
        if (!fl)
        {
            puts("-1");
            continue;
        }
        int sum = 0;
        fir(i, 1, n)
        {
            if (color[find(i)] == 0)
            {
                res = cnt = 0;
                if (!dfs(find(i), 1))
                    fl = false;
                sum += max(res, cnt - res);
            }
        }
        if (!fl)
        {
            puts("-1");
        }
        else
            cout << sum << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}