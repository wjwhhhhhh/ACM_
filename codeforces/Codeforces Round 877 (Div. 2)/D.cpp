#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        int m, q;
        cin >> m >> q;
        string a;
        cin >> a;
        a = " " + a;
        set<pair<int, int> > x, y;
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (a[i] == '(')ans++;
            else ans--;
        }
        for (int i = 2; i <= m; i++)
        {
            if (a[i] == a[i - 1] && a[i] == '(')x.insert({i - 1, i});
            else if (a[i] == a[i - 1] && a[i] == ')')y.insert({i - 1, i});
        }
        while (q--)
        {
            int p;
            cin >> p;
            if (m & 1)
            {
                cout << "NO" << endl;
                continue;
            }
            if (a[p] == '(')
            {
                a[p]=')';
                ans -= 2;
                if(p==2)
                {

                }
                if (p + 1 <= m && a[p + 1] == '(')x.erase({p, p + 1});
                if (p + 1 <= m && a[p + 1] == ')')y.insert({p, p + 1});
                if (p > 1 && a[p - 1] == '(')x.erase({p - 1, p});
                if (p > 1 && a[p - 1] == ')')y.insert({p - 1, p});

            }
            else
            {
                a[p]='(';
                ans += 2;
                if (p + 1 <= m && a[p + 1] == '(')x.insert({p, p + 1});
                if (p + 1 <= m && a[p + 1] == ')')y.erase({p, p + 1});
                if (p > 1 && a[p - 1] == '(')x.insert({p - 1, p});
                if (p > 1 && a[p - 1] == ')')y.erase({p - 1, p});
            }
            // if(q==9)
            // {
            //     cout<<a<<endl;
            // }
            if(a[1]==')')
            {
                cout<<"NO"<<endl;
            }
            else if(x.size()==0&&y.size()==0)
            {
                cout<<"YES"<<endl;
            }
            else if(x.size()==0||y.size()==0)
            {
                cout<<"NO"<<endl;
            }
            else if ((*y.begin()).first>(*x.begin()).first)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}