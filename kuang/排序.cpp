#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
   int n;
   cin>>n;
   int l=1,r=n;
   vector<int> a(n+1);
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)if(a[i]==i)l++;else break;
   if(l>n)
   {
    cout<<"0 0"<<endl;
    return 0;
   }
    while(a[r]==r)r--;
    cout<<l<<" "<<r<<endl;
    return 0;
}