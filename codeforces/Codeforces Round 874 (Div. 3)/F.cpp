
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9 + 7, N = 2e5 + 10;
int n, m;
long long qmi(long long k, long long p = M - 2)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
void solves()
{

    cin >> n >> m;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)cin >> a[i], mp[a[i]]++;
    sort(a.begin(), a.end());
    a.erase( unique(a.begin(), a.end()),a.end());
    if (m == 1)
    {
        int ans = 0;
        for (int i = 0; i < a.size(); i++)ans = (ans + mp[a[i]]) % M;
        cout << (ans+M)%M << endl;
        return ;
    }
    //cout<<a.size()<<" ";
    int si = 1, ans = 0, tem = mp[a[0]];
    for (int i = 1; i<a.size(); i++)
    {
        //cout<<si;
        if (a[i] == a[i - 1]+1)si++, tem =(tem* mp[a[i]])%M;
        else si = 1, tem = mp[a[0]];
        if (si == m)
        {
            ans=(ans+tem)%M;
            si--;
            tem=tem*qmi(mp[a[i-m+1]])%M;
        }
    }
    cout<<(ans+M)%M<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}