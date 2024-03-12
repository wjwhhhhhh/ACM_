#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a{0,0,2,3,3,4};
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(a.size()>n)cout<<a[n]<<endl;
        else cout<<(n+1>>1)+1<<endl;
    }
    return 0;
}