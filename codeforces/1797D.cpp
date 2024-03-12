#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
typedef pair<int, int> PII;
// #define read(x) scanf("%d",&x)
const int N = 1e5 + 10;
struct node
{
    int parent;
    set<PII> son;
    int son_size;
    long long value;
    long long impo;
} no[N];
int h[N], e[2 * N], ne[2 * N], idx = 1;
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int fa)
{
    no[u].impo = no[u].value;
    no[u].parent = fa, no[u].son_size = 1;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            dfs(j, u);
            no[u].son_size += no[j].son_size;
            no[u].son.insert({no[j].son_size, -j});
            no[u].impo += no[j].impo;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> no[i].value;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, -1);
    while (m--)
    {
        int flag, x;
        cin >> flag >> x;
        if (flag == 1)
        {
            cout << no[x].impo << "\n";
        }
        else
        {
            if (no[x].son.size() == 0)
                continue;
            int pa = no[x].parent, son = -no[x].son.rbegin()->second;
            no[pa].son.erase({no[x].son_size, -x});
            no[x].son.erase({no[son].son_size, -son});
            no[x].impo -= no[son].impo, no[son].impo += no[x].impo;
            no[x].son_size -= no[son].son_size, no[son].son_size += no[x].son_size;
            no[x].parent = son, no[son].parent = pa;
            no[son].son.insert({no[x].son_size, -x});
            no[pa].son.insert({no[son].son_size, -son});
        }
    }
    return 0;
}