#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64=long long;
vector<i64> divisor(i64 n)
{
    vector<i64> p;
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i), p.push_back(n / i);
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
    int ans=0;
    for(int i=1;i<=1e6;i++)
    {
        ans=max(ans,(int)divisor(i).size());
    }
    cout<<ans<<endl;
    return 0;
}