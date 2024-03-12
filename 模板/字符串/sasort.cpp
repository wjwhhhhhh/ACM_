#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct SA
{
    vector<int> sa, rk, he;
    vector<int> s;
    int n;
    SA()
    {
    }
    void work()
    {
        int i, p, w;
        n = s.size();
        s.insert(s.begin(),0);
        sa.resize(n + 1), he.resize(n + 1),rk.resize(n+1);
        vector<int> oldrk(n + 1 << 1), rank(n + 1 << 1);
        for (i = 1; i <= n; ++i)
            sa[i] = i, rank[i] = s[i];
        for (w = 1; w < n; w <<= 1)
        {
            sort(sa.begin() + 1, sa.end(),
                 [&](int x, int y) { return rank[x] == rank[y] ? rank[x + w] < rank[y + w] : rank[x] < rank[y]; });
            oldrk = rank;
            for (p = 0, i = 1; i <= n; ++i)
            {
                if (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                {
                    rank[sa[i]] = p;
                }
                else
                {
                    rank[sa[i]] = ++p;
                }
            }
        }
        sa[0]=n+1;
        n++;
        for(auto &x:sa)x--;
        for(int i=0;i<n;i++) rk[sa[i]]=i;
        s.erase(s.begin(),s.begin()+1);
        s.push_back(0);
        for(int i=0,k=0;i<n-1;i++)
        {
            if(k)k--;
            while(s[i+k]==s[sa[rk[i]-1]+k])k++;
            he[rk[i]]=k;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    SA sa;
    cin >> sa.s;
    sa.work();
    return 0;
}