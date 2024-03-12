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
const int N = 2100, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool v[M];
int d[N];
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
vector<int>bian;
int te,si;
int fa[N];
vector<PII> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        memset(d, 0, sizeof(int) * (n + 5));
        memset(h, -1, sizeof(int) * (n + 5)), idx = 0;
        memset(d, 0, sizeof(int) * (n + 5));
        cin >> n >> m;
        set<int> ans;
        ans.clear();
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b),add(b,a);
            d[a]++,d[b]++;
            if(d[a]>=4)ans.insert(a);
            if(d[b]>=4)ans.insert(b);
        }
        for(auto i:ans)
        {
            if(fl)continue;
            te=i;
            memset(v, 0, sizeof(int) * (2*m + 5));
            bian.clear();
            for(int tr=h[i];~tr;tr=ne[tr])
            {
                bian.push_back(tr);
            }
            dfs(0,0);
        }
        if(!fl)cout<<"NO"<<endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}