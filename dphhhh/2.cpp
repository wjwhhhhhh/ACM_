//   ▄███████▀▀▀▀▀▀███████▄
// ░▐████▀▒▒▒▒▒▒▒▒▒▒▒▀██████▄
// ░███▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀█████
// ░▐██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
// ░▐█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
// ░░█▒▄▀▀▀▀▀▄▒▒▄▀▀▀▀▀▄▒▐███▌
// ░░░▐░░░▄▄░░▌▐░░░▄▄░░▌▐███▌
// ░▄▀▌░░░▀▀░░▌▐░░░▀▀░░▌▒▀▒█▌
// ░▌▒▀▄░░░░▄▀▒▒▀▄░░░▄▀▒▒▄▀▒▌
// ░▀▄▐▒▀▀▀▀▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒█
// ░░░▀▌▒▄██▄▄▄▄████▄▒▒▒▒█▀
// ░░░░▄██████████████▒▒▐▌
// ░░░▀███▀▀████▀█████▀▒▌
// ░░░░░▌▒▒▒▄▒▒▒▄▒▒▒▒▒▒▐
// ░░░░░▌▒▒▒▒▀▀▀▒▒▒▒▒▒▒▐

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k,p;
    cin >> n >> k >> p;
    int a[n],b[k];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
        cin >> b[i];
    sort(a,a+n);
    int l=0,r=-1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            r=max(r,abs(a[i]-b[j])+abs(b[j]-p));
    r+=10;
    while(l<r)
    {
        int dist=(l+r)/2;
        multiset<int> se;
        for (int i = 0; i < k; ++i)
            se.insert(b[i]);
        bool sign=true;
        for (int i = 0; i < n; ++i)
        {
            bool flag=false;
            for(int j:se)
                if(abs(a[i]-j)+abs(j-p)<=dist)
                {
                    se.erase(se.find(j));
                    flag=true;
                    break;
                }
            if(flag==false)
            {
                sign=false;
                break;
            }
        }
        if(l+1==r)
        {
            if(sign==true)
            {
                cout << l << endl;
                return;
            }
            cout << r << endl;
            return;
        }
        if(sign==true)
            r=dist;
        else
            l=dist+1;
    }
    cout << l << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // int t;
    // cin >> t;
    // while(t--)
        solve();
    return 0;
}