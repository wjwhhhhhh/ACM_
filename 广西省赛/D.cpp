#include <bits/stdc++.h>
using namespace std;
using i64=long long;
struct DSU
{
    std::vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    DSU f(3*n);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        f.merge(a,b);
    }
    int ans=0;
    set<int> st;
    for(int i=0;i<3*n;i++)
    {
        int fa=f.find(i);
        if(st.find(fa)!=st.end())continue;
        if(f.size(fa)%3!=0)ans+=2;
        st.insert(fa);
    }
    cout<<ans<<endl;
    return 0;
}