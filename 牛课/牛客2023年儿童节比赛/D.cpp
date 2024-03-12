#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    std::vector<int> a(6);
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    int l=0,r=1e6;
    auto check = [&](int x)
    {
        int si=0;
        for(int i=1;i<=5;i++)
        {
            si+=b[i];
            si-=i*x;
            if(si<0)return false;
        }
        return true;
    }
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}