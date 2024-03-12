#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    map<pair<int,int>,int > has;
    for(int i=0;i+1<n;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            if(has.find({a[i]+a[i+1]+a[j],b[i]+b[i+1]+b[j]})!=has.end())
            {
                cout<<"YES"<<endl;
                int id=has[{a[i]+a[i+1]+a[j],b[i]+b[i+1]+b[j]}];
                cout<<i<<" "<<i+1<<" "<<id<<endl;
                cout<<i<<
            }
        }
    }
    return 0;
}