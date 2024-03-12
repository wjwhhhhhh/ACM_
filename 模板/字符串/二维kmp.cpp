#include <bits/stdc++.h>
using namespace std;
struct double_kmp // 默认全从0开始
{
    static const int S = 1010;
    int n1, n2, m1, m2;
    vector<string> a, b, tt;
    double_kmp()
    {
    }
    double_kmp(int n1, int n2 = -1)
    {
        init(n1, n2);
    }
    void init(int n1, int n2 = -1)
    {
        if (n2 == -1)
            n2 = n1;
        a.resize(n1), b.resize(n2), tt.resize(n1);
    }
    bool op(int l, int r, int x)
    {
        for (int i = x; i < x + n2; i++)
        {
            if (tt[i][l] != tt[i][r])
                return false;
        }
        return true;
    }
    vector<int> prefix_function(int x) // 计算前缀函数
    {
        
        int n = (int)tt[x].length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && !op(i, j, x))
                j = pi[j - 1];
            if (op(i, j, x))
                j++;
            pi[i] = j;
        }
        return pi;
    }
    vector<int> find_occurrences(int i) // kmp  找pattern在text出现的位置
    {
        for (int j = i; j < i + n2; j++)
            tt[j] = b[j - i] + '#' + a[j];
        int sz1 = m1, sz2 = m2;
        vector<int> v;
        vector<int> lps = prefix_function(i);
        for (int i = sz2 + 1; i <= sz1 + sz2; i++)
        {
            if (lps[i] == sz2)
                v.push_back(i - 2 * sz2);
        }
        return v;
    }
    vector<vector<int>> final_find_find_occurrences()
    {
        vector<vector<int>> ans;
        for (int i = 0; i + n2 - 1 < n1; i++)
        {
            auto tem = find_occurrences(i);
            
            ans.push_back(tem);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double_kmp tem(1010);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> tem.n1 >> tem.m1;
        for (int i = 0; i < tem.n1; i++)
            cin >> tem.a[i];
        cin >> tem.n2 >> tem.m2;
        for (int i = 0; i < tem.n2; i++)
            cin >> tem.b[i];
        auto ans = tem.final_find_find_occurrences();
        int sum = 0;
        for (auto i : ans)
        {
            sum += i.size();
        }
        cout<<sum<<'\n';
    }
}
