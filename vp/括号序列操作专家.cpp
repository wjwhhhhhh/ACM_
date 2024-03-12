#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
string str;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> str;
        str = ' ' + str;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (str[i] == ')')
            {
                cnt++;
            }
        }
        if (n & 1 || cnt != n / 2)
        {
            cout << -1 << endl;
            continue;
        }
        int res = 0;
        queue<int> l, r;
        for (int i = n; i >= 1; i--)
        {
            if (str[i] == '(')
                l.push(i);
            else
                r.push(i);
        }
        priority_queue<int> pos;
        while (l.size())
        {
            if (l.front() > r.front())
            {
                while (pos.size() && pos.top() > l.front())
                    pos.pop();
                int cnt = pos.size();
                res += l.front() - r.front() - cnt;
                //                 cout << cnt << " " << l.front() << endl;
                pos.push(r.front());
            }
            l.pop();
            r.pop();
        }
        cout << res << endl;
    }
    return 0;
}
