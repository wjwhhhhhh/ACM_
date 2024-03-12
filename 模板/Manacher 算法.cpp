
#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 100, M = 100;
void Manacher(vector<int> &d1, vector<int> &d2,
              string s) // 二者也表示了以位置 i 为中心的最长回文串的半径长度（半径长度 d_1[i]，d_2[i] 均为从位置 i
                        // 到回文串最右端位置包含的字符个数）。
{
    int n = s.size();
    d1.resize(n), d2.resize(n);
    fill(d1.begin(), d1.end(), 0), fill(d2.begin(), d2.end(), 0);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
}
string get(int len)
{
    string res(len,'a');
    for(int i=0;i<len/2;i++)
    {
        int t=rnd()%3+'a';
        res[i]=char(t);
        res[len-1-i]=char(t);
    }
    return res;
};
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    cout << M << endl;
    for (int t = 1; t <= M; t++)
    {
        cout << N << endl;
        string a;
        int len=0;
        while(len<N)
        {
            int l=rnd()%(N-len)+1;
            a+=get(l);
            len+=l;
        }
        vector<int>d1,d2;
        Manacher(d1,d2,a);
        for(auto x:d1)cout<<x<<" ";
            cout<<endl;
    }
    return 0;
}
