#include <stdio.h>
#define N 20
#define M 3  // 页面长度,进程的分配的物理块长度
int idx = 0; // 置换次数
int data[N] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
void OPT()
{
    int tem[M];
    int has = 0;
    idx = 0;
    for (int i = 0; i < N; i++)
    {
        int fl = 0;
        for (int j = 0; j < has; j++)
        {
            if (tem[j] == data[i])
                fl = 1;
        }
        if (fl)
        {
            printf("内存中已经有%d\n", data[i]);
        }
        else if (has != M)
        {
            idx++;
            tem[has++] = data[i];
            printf("内存可以装下，%d被装下\n", data[i]);
        }
        else
        {
            idx++;
            int time[M];
            for (int j = 0; j < has; j++)
            {
                time[j] = -1;
                for (int z = i + 1; z < N; z++)
                {
                    if (data[z] == tem[j] && tem[j] == -1)
                        time[j] = z;
                }
            }
            int res = 0;
            for (int j = 0; j < has; j++)
            {
                if (time[res] < time[j])
                    res = j;
            }
            printf("内存不可以装下，%d被置换，%d被装下\n", tem[res], data[i]);
            tem[res] = data[i];
        }
        printf("内存已经有");
        for (int i = 0; i < has; i++)
            printf("%d ", tem[i]);
        printf("\n");
    }
    printf("缺页次数为%d\n", idx);
    printf("缺页率为%lf\n", idx * 1.0 / N);
}
void FIFO()
{
    int has[M + 1];
    int len = M + 1;
    int hh = 0, tt = 0;
    idx = 0;
    for (int i = 0; i < N; i++)
    {
        int fl = 0;
        for (int j = hh;; j++)
        {
            if (j == len)
                j = 0;
            if (j == tt)
                break;
            if (has[j] == data[i])
                fl = 1;
        }
        if (fl)
        {
            printf("内存中已经有%d\n", data[i]);
        }
        else if ((tt + len - hh) % len != M)
        {
            idx++;
            has[tt++] = data[i];
            if (tt == len)
                tt = 0;
            printf("内存可以装下，%d被装下\n", data[i]);
        }
        else
        {
            idx++;
            printf("内存不可以装下，%d被置换，%d被装下\n", has[hh++], data[i]);
            if (hh == len)
                hh = 0;
            has[tt++] = data[i];
            if (tt == len)
                tt = 0;
        }
        printf("内存已经有");
        for (int j = hh;; j++)
        {
            if (j == len)
                j = 0;
            if (j == tt)
                break;
            printf("%d ", has[j]);
        }
        printf("\n");
    }
    printf("缺页次数为%d\n", idx);
    printf("缺页率为%lf\n", idx * 1.0 / N);
}
void LRU()
{
    int has[M + 1];
    int len = M + 1;
    int hh = 0, tt = 0;
    idx = 0;
    int tem[M];
    int id = 0;
    for (int i = 0; i < N; i++)
    {
        int fl = 0;
        for (int j = hh;; j++)
        {
            if (j == len)
                j = 0;
            if (j == tt)
                break;
            tem[id] = has[j];
            if (has[j] == data[i])
                fl = 1;
        }
        if (fl)
        {
            int res = 0;
            for (int j = 0; j < id; j++)
            {
                if (tem[j] == data[i])
                    res = j;
            }
            int re = tem[res];
            for (int j = res; j < id - 1; j++)
            {
                tem[j] = tem[j + 1];
            }
            tem[id - 1] = re;
            for (int j = hh;; j++)
            {
                if (j == len)
                    j = 0;
                if (j == tt)
                    break;
                has[j] = tem[--id];
            }
            printf("内存中已经有%d\n", data[i]);
            printf("更新他的t %d\n", data[i]);
        }
        else if ((tt + len - hh) % len != M)
        {
            idx++;
            has[tt++] = data[i];
            if (tt == len)
                tt = 0;
            printf("内存可以装下，%d被装下\n", data[i]);
        }
        else
        {
            idx++;
            printf("内存不可以装下，%d被置换，%d被装下\n", has[hh++], data[i]);
            if (hh == len)
                hh = 0;
            has[tt++] = data[i];
            if (tt == len)
                tt = 0;
        }
        printf("内存已经有");
        for (int j = hh;; j++)
        {
            if (j == len)
                j = 0;
            if (j == tt)
                break;
            printf("%d ", has[j]);
        }
        printf("\n");
    }
    printf("缺页次数为%d\n", idx);
    printf("缺页率为%lf\n", idx * 1.0 / N);
}
int main()
{
    FIFO();
}