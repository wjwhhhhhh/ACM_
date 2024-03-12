#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
int find(vector<int>&wei,int x)
{
    int l=0,r=wei.size()-1;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(wei[mid]<=x)l=mid;
        else r=mid-1;
    }
    return wei[l];
}
int get(int x)
{
    return (x-1)/2;
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i ++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    if(a[0]==1)
    {
        cout<<"1"<<endl;
        return ;
    }
    vector<int> wei;
    wei.push_back(1);
    for(int i=2;i<=a[0]/i;i++)
    {
        if(a[0]%i==0)
        {
            wei.push_back(i);
            if(a[0]/i!=i)wei.push_back(a[0]/i);
        }
    }
    if(a[0]!=1)wei.push_back(a[0]);
    sort(wei.begin(),wei.end());
    int ans=get(a[0]);
    int cgcd=a[0];
    for(int i=1;i<n;i++)
    {
        while(cgcd<wei.back())wei.pop_back();
        ans=max(ans,find(wei,get(a[i])));
        cgcd=__gcd(cgcd,a[i]);
    }
    ans=max(ans,cgcd);
    cout<<ans<<endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t = 1;
//    std::cin >> t;

    while (t --) {
        solve();
    }

    return 0;
}