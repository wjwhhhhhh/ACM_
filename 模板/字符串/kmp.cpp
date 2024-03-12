#include <bits/stdc++.h>
using namespace std;
// 从 0开始
bool op(char a, char b)
{
    return a == b;
}
vector<int> prefix_function(string s) // 计算前缀函数
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && !op(s[i], s[j]))
            j = pi[j - 1];
        if (op(s[i], s[j]))
            j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> find_occurrences(string pattern, string text) // kmp  找pattern在text出现的位置
{
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = prefix_function(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++)
    {
        if (lps[i] == sz2)
            v.push_back(i - 2 * sz2);
    }
    return v;
}
void compute_automaton(string s, vector<vector<int>> &aut)//kmp自动机
{
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i - 1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}
![Image](https://pic4.zhimg.com/80/v2-6d5969a8940eef9723d2305b988c0a1b.gif)