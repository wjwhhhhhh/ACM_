#include <bits/stdc++.h>
using namespace std;
struct PAM
{
    vector<int> fail,num,len;
    vector<array<int,26> >ch;
    int last,cnt;
    PAM()
    {

    }
    PAM(string a)
    {
        init(a);
    }
    void init(string s)
    {
        int n=s.size();
        len[0] = 0,len[1] = -1;
        fail[0] = 1, fail[1] = 0;
        last = 0,cnt = 1;
        fail.resize(n),num.resize(n),len.resize(n);
        ch.resize(n);
    }
    void insert()
    {
        for(int i=0)
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    }
    return 0;
}