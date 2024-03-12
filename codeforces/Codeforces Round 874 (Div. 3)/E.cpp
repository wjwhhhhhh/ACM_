#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
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
void solves()
{
    int n;
    cin>>n;
    DSU f(n);
    int ans=0;
    set<pair<int,int> > st;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        b--;
        if(b<i&&st.find({b,i})!=st.end())continue;
        if(b>i&&st.find({i,b})!=st.end())continue;
        st.insert({min(i,b),max(i,b)});
        if(f.same(i,b))ans++;
        f.merge(i,b);
    }
    set<int> at;
    for(int i=0;i<n;i++)at.insert(f.find(i));
    cout<<(ans==at.size()?ans:ans+1)<<" ";
    cout<<at.size()<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}