#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 114514;
long long a[N], qq[N], b[N];
int n, q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (n == 1)
    {
        while(q--)
        {
            int k;
            cin>>k;
            if(k&1)cout<<a[1]+k-k/2<<" ";
            else cout<<a[1]-k/2<<" ";
        }
        return 0;
    }
    qq[0] = a[1];
    for (int i = 1; i < n; i++)
    {
        qq[i] = min(qq[i - 1] + 1 , a[i + 1]);
    }
    qq[n] = qq[n - 1] + 1;
    int ans = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (a[i] + n + 1 - i) - qq[n];
        if (i != n)ans2 += (a[i] + n - i) - qq[n - 1];
    }
    while (q--)
    {
        int k;
        cin >> k;
        if (k <= n)cout << qq[k] << ' ';
        else if ((k - n) % 2 == 0)
        {
            int si = (k - n) / 2;
            int as = qq[n];
            if (si <= ans)
            {
                as += si * 2;
            }
            else
            {
                as += ans * 2;
                si -= ans;
                as += (si / n) * (2 * n - 1);
                si = si % n;
                as += si * 2;
                if (si)as--;
            }
            cout << as << " ";
        }
        else
        {
            int si = (k - n + 1) / 2;
            int tem = qq[n - 2] + 1;
            tem = tem + si * 2;
            si -= ans2;
            if (a[n] > tem)
            {
                si -= (a[n] - tem);
            }
            else
            {
                si -= (n - 1) * (tem - a[n]);
            }
            tem = min(tem, a[n]);
            if (si <= 0)
            {
                cout << tem << ' ';
            }
            else
            {
                si = (si + n - 1) / n;
                tem -= si;
                cout << tem << " ";
            }
        }
    }
    return 0;
}