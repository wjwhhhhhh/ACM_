#include <bits/stdc++.h>
#define dug(x) cerr << "death" << x << endl
using namespace std;
using i64=long long;
const int M=998244353;
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N=1e6+10;
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size, edge_size;
    Graph()
    {
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n, int m)
    {
        node_size = n;
        edge_size = m;
        idx = 0, e.resize(m), ne.resize(m), w.resize(m);
        h.resize(n, -1);
    }
    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c)
    {
        w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
};
bool op(char a, char b)
{
    return a == b;
}
vector<int> prefix_function(string &s) // 计算前缀函数
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && !op(s[i], s[j]))
            j = pi[j - 1];
        if (op(s[i], s[j]))
            j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> euler_function(int x)
{
    vector<int> q, s(x + 1), idx;
    vector<int> st(x + 1);
    s[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
            q.push_back(i), s[i] = i - 1;
        for (int j = 0; q[j] <= x / i; j++)
        {
            st[q[j] * i] = true;
            if (i % q[j] == 0)
            {
                s[q[j] * i] = s[i] * q[j];
                break;
            }
            s[q[j] * i] = s[i] * (q[j] - 1);
        }
    }
    return s;
}
void divisor(int n,vector<int> &p)
{
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i);
             if(n/i!=i)p.push_back(n / i);
        }
    }
}
vector<vector<int>> p(N+1);
vector<int> eul,f(N),st(N);
void solve()
{
    string a;
    cin>>a;
    int n=a.size();
    fill(f.begin(),f.begin()+n+5,0);
    Graph gra(n+1,n);
    auto nex=prefix_function(a);
    for(int i=0;i<n;i++)
    {
        gra.add(nex[i],i+1);
    }
    for(int i=1;i<=n;i++)divisor(i,p[i]);
    function<void(int,int)>dfs=[&](int u,int fa)
    {
        for(auto x:p[u])
        {
            f[u]=(f[u]+st[x]*eul[x])%M;
            st[x]++;
        }
        for(int i=gra.h[u];~i;i=gra.ne[i])
        {
            int j=gra.e[i];
            if(j!=fa)
            {
                dfs(j,u);
            }
        }
        for(auto x:p[u])
        {
            st[x]--;
        }
    };
    dfs(0,-1);
    i64 ans=1;
    for(int i=1;i<=n;i++)ans=ans*(f[i]+1)%M;
        cout<<ans<<endl;
}
int main()
{
    int size(512<<20); // 512M
__asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(false);
    cin.tie(0);
    eul=euler_function(N);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    exit(0);
    return 0;
}