#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 998244353, N = 5e5 + 10;
int a[N];
int s[N];
int fac[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<int>a(1 << k + 1);
    for (int i = 1; i <= 1 << k; i++)cin >> a[i];
    i64 ans = 1;
    fac[0] = 1;
    for (int i = 1; i <= 1 << k; i++)fac[i] = 1ll * fac[i - 1] * i % M;
    vector<int> tr(1 << k+1), tt(1 << k+1);
    for (int i = 1; i <= 1 << k; i++)if (a[i] != -1)tr[i] = a[i];
    auto check = [&](int tem, int k)
    {
        return tem > (1 << k);
    };
    int si = 0;
    while (k--)
    {
        si = 0;
        // for(auto i:tr)cout<<i<<" ";
        //     cout<<endl;
        //cout<<k<<endl;
        for (int i = 1; i <= 1 << k + 1; i += 2)
        {
            //cout<<(1<<k+1)<<endl;
            if (check(tr[i], k) && check(tr[i + 1], k))
            {
                cout << "0" << endl;
                return 0;
            }
            else if (check(tr[i], k))
            {
                tt[(i + 1) / 2] = tr[i+1];
            }
            else if (check(tr[i + 1], k))
            {
                 tt[(i + 1) / 2] = tr[i];
            }
            else
            {
                if (tr[i] > 0 && tr[i + 1] > 0)
                {
                    cout << "0" << endl;
                    return 0;
                }
                else if(tr[i]>0)
                {

                    tt[(i + 1) / 2] = tr[i];
                }
                else if(tr[i+1]>0)
                {

                     tt[(i + 1) / 2] = tr[i+1];
                }
                else ans=ans*2%M,tt[(i+1)/2]=0;
                si++;
            }

        }
        tr=tt;
        ans = ans * fac[si] % M;
        //cout<<ans<<endl;

    }
    cout<<ans<<endl;
    return 0;
}