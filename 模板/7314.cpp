#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int> mp,all;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int len;
        cin>>len;
        for(int j=0;j<len;j++)
        {
            int a;
            cin>>a;
            all.push_back(a);
            mp.push_back(idx);
        }
        idx++;
    }
    vector<int>o(all.size());
    iota
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