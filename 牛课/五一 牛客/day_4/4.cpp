#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
set<int> at[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int string tem;
    cin>>tem;
    tem=" "+tem;
    for(int i=1;i<tem.size();i++)
    {
        at[tem[i]-'a'].insert(i);
    }

    return 0;
}