#include <bits/stdc++.h>
using namespace std;
using i64=long long;
#include <bits/stdc++.h>
using namespace std;
struct Tire//字母
{
    static const int W = 10;
    int cnt;
    vector<array<int, W>> nex;
    vector<int> size;
    Tire(){};
    Tire(int n)
    {
        init(n);
    }
    void init(int n)
    {
        cnt=0;
        nex.resize(n+5); // 根据需要修改
        size.resize(n + 5);
    }
    void add(string t)
    {
        int p = 0;
        for (int i = 0; i < t.size(); i++)
        {
            int c = t[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
        }
        size[p]++;
    }
    bool find(string s) // 找出现次数
    {                // 查找字符串
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return false;
            p = nex[p][c];
            if(size[p])return true;
        }
        return false;

    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> te(m);
    for(int i=0;i<m;i++)cin>>te[i];
    sort(te.begin(),te.end(),[&](string a,string b){
       return a.size()<b.size();
    });
    int ans=0;
    int l=0;
    Tire tr(55);
    for(int i=1;i<=n;i++)
    {
        ans=ans*10;
        set<string> tem;
        while(l<m&&te[l].size()==i)tem.insert(te[l++]);
        for(auto str:tem)
        {
            if(!tr.find(str))ans++;
            tr.add(str);
        }
        cout<<ans<<" ";
    }
    return 0;
}