#include <bits/stdc++.h>
using namespace std;
struct Tire // 字母
{
    static const int W = 26;
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
        cnt = 0;
        nex.resize(n + 5); // 根据需要修改
        size.resize(n + 5);
    }
    int add(string t)
    {
        int p = 0;
        for (int i = 0; i < t.size(); i++)
        {
            int c = t[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
        }
        return p;
        size[p]++;
    }
    int find(string s) // 找出现次数
    {                  // 查找字符串
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return 0;
            p = nex[p][c];
        }
        return size[p];
    }
};