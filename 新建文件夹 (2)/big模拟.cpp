#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int N = 110;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    int root = 0;
    int idx = 0;
    vector<vector<string>> has(N); // all
    vector<vector<int>> edg(N);    // 文件夹
    vector<int> fa(N);
    map<int, string> name;
    map<string, int> mp;
    name[idx] = "admin:~$";
    mp["admin:~$"] = idx;
    int ing = 0;
    while (cin >> a)
    {
        if (a == "ls")
        {
            if (has.size() == 0)
            {
                cout << "empty";
            }
            else
                for (auto c : has[ing])
                    cout << c << " ";
        }
        else if (a == "mkdir")
        {
            string need;
            cin >> need;
            if (find(has[ing].begin(), has[ing].end(), need) != has[ing].end())
            {
                cout << "cannot create directory ";
                cout << need << " File exists";
            }
            else
            {
                has[ing].push_back(need);
                fa[idx + 1] = ing;
                edg[ing].push_back(idx++);
                name[idx] = need;
                mp[need] = idx;
                cout << "have no out put";
            }
        }
        else if (a == "cd")
        {
            string need;
            cin >> need;
            if (need == "..")
            {
                if (ing == 0)
                {
                    cout << "now is first level,can not cd";
                }
                else
                {
                    ing = fa[ing];
                    cout << name[0] << "/" << name[ing];
                }
            }
            if (find(need.begin(), need.end(), '.') == need.end() &&
                find(has[ing].begin(), has[ing].end(), need) != has[ing].end())
            {
                ing = mp[need];
                cout << name[0] << "/" << name[ing];
            }
            else
            {
                cout << "error,can't cd a file ";
            }
        }
    }
    return 0;
}