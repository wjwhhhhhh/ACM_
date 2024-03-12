#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
std::vector<i64> factorize(i64 n)
{
    vector<i64> p;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i);
            p.push_back(n / i);
        }
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    return p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, x;
    cin >> m >> x;
    vector<array<int, 2> > tr(m+1);
    for (int i = 1; i <= m; i++)
    {
        cin >> tr[i][0] >> tr[i][1];
    }
    int tt=0;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(tr[i][0]!=tr[i][1])tt=i;
        else ans=max(ans,tr[i][1]);
    }
    if(tt=0)
    {
        cout<<min(x-ans,0)<<endl;
        return 0;
    }
    set<int> f1, f2;
    int a=tr[tt][0],b=tr[tt][1];
    auto p = factorize(a - b);
    for (auto i : p)
    {
        if (i > b && i <= x)f1.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if(i==tt)continue;
        f2 = f1;
        a=tr[i][0],b=tr[i][1];
        f1.clear();
        for (auto i : f2)
        {
            if (i>b&&(a-b)%i==0)f1.insert(i);
        }
    }
    cout<<f1.size()<<endl;
    return 0;
}