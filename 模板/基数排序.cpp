#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const size_t MAXBUCKET = 128;

// 注意一定要将这两套容器放在执行递归操作的函数外边，否则很有可能 MLE / RE
queue<string> bucket[MAXBUCKET];     // 存储具有相同关键字的元素，注意使用 queue
                                     // 这种 FIFO 型数据结构才能使排序稳定
string *borders[MAXBUCKET + 1] = {}; // 具有相同关键字元素的范围边界，注意是 [L, R) 形式的
string buks[110];
// [first, last) 里的元素是每个字符串
// offset 表示访问每个字符串的第 offset 个字符，即第 offset 关键字
void MSD_radix_sort(string *first, string *last, size_t offset = 0)
{
    // cerr<<offset<<endl;
    //  如果只剩一个字符串，直接返回
    if (last - first <= 1)
        return;

    // 使用基于 queue 实现的计数排序分组，存储到 bucket 里
    for (string *iter = first; iter != last; ++iter)
    {
        char ch = (*iter)[offset]; // 获取字符串 *iter 的第 offset 个关键字
        size_t idx = ch;
        bucket[idx].push(*iter); // 将字符串放进对应的 bucket 里
    }

    // 倒回原数组，iter 记录当前数组末端的位置
    string *iter = first;
    borders[0] = first;

    // 由于已知 0 < 1 < ... < MAXBUCKET-1，所以按关键字从小到大清空各个 bucket
    // 即可完成基于第 offset 个关键字的排序
    for (size_t idx = 0; idx < MAXBUCKET; ++idx)
    {
        // 清空第 idx 个 bucket
        while (!bucket[idx].empty())
        {
            *iter++ = bucket[idx].front();
            bucket[idx].pop();
        }

        // 记录当前组的右边界，左边界 border[idx] 已经事先记录过了
        borders[idx + 1] = iter;
    }

    // 递归对具有相同关键字的元素进行下一关键字的排序
    for (int idx = 0; idx < MAXBUCKET; ++idx)
        if (borders[idx] != borders[idx + 1]) // 非空
            MSD_radix_sort(borders[idx], borders[idx + 1], offset + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cin >> buks[i];
    MSD_radix_sort(buks + 1, buks + 5);
    for (int i = 1; i <= t; i++)
        cout << buks[i] << endl;
    return 0;
}