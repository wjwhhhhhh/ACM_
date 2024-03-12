#include <stdio.h>
const int M = 3;                                                      // 资源种类
const int N = 5;                                                      // 进程数量
int Available[M] = {3, 3, 2};                                         // 可利用资源向量
int Max[N][M] = {7, 5, 3, 3, 2, 2, 9, 0, 2, 2, 2, 2, 4, 3, 3};        // 最大需求矩阵
int Allocation[N][M] = {0, 1, 0, 2, 0, 0, 3, 0, 2, 2, 1, 1, 0, 0, 2}; // 分配矩阵
int Need[N][M] = {7, 4, 3, 1, 2, 2, 6, 0, 0, 0, 1, 1, 4, 3, 1};       // 需求矩阵,还要
bool check1(int id, int Request[M])                                   // 检查是否合法
{
    printf("正在进行检查的第一步，此时的进程为%d", id);
    for (int i = 0; i < M; i++)
    {
        if (Request[i] > Need[id][i])
            return false;
    }
    return true;
}
bool check2(int id, int Request[M]) // 检查是否有资源分配
{
    printf("正在进行检查的第二步，此时的进程为%d", id);
    for (int i = 0; i < M; i++)
    {
        if (Request[i] > Available[id])
            return false;
    }
    return true;
}
void assign(int id, int Request[M]) // 分配函数
{
    for (int i = 0; i < M; i++)
    {
        Available[i] = Available[i] - Request[i];
        Allocation[id][i] = Allocation[id][i] + Request[i];
        Need[id][i] = Need[id][i] - Request[i];
    }
}
int SAFE[N];
bool check_safe() // 安全算法
{
    int Work[M];   // 工作向量
    bool Finsh[N]; // 完成向量
    for (int i = 0; i < M; i++)
        Work[i] = Available[i];
    for (int i = 0; i < N; i++)
        Finsh[i] = false;
    int idx = 0;
    while (1)
    {
        int id = -1;
        for (int i = 0; i < N; i++)
        {
            if (!Finsh[i])
            {
                bool fl = true;
                for (int j = 0; j < M; j++)
                {
                    if (Need[i][j] > Work[j])
                        fl = false;
                }
                if (fl)
                    id = i;
            }
        }
        if (id == -1)
            break;
        else
        {
            for (int i = 0; i < M; i++)
            {
                Work[i] += Allocation[id][i];
            }
            Finsh[id] = true;
            SAFE[idx++] = id;
        }
    }

    printf("检查完毕\n");
    printf("   Work    Need    Allocation  Work +Allocation  Finsh\n");
    printf("   A B C   A B C   A  B  C        A  B  C   \n");
    for (int i = 0; i < M; i++)
        Work[i] = Available[i];
    for (int i = 0; i < N; i++)
    {
        printf("%d ", SAFE[i]);
        printf("%d %d %d %d %d %d %d %d %d %d", Work[0], Work[1], Work[2], Need[0], Need[1], Need[2],
               Allocation[SAFE[i]][0], Allocation[SAFE[i]][0], Allocation[SAFE[i]][0]);
        for (int j = 0; j < M; j++)
        {
            Work[j] += Allocation[SAFE[i]][j];
        }
        printf("%d %d %d", Work[0], Work[1], Work[2]);
        printf("%d\n", Finsh[SAFE[i]]);
    }
    for (int i = 0; i < N; i++)
    {
        if (!Finsh[i])
            return false;
    }
    return true;
}
int main()
{
    if (!check_safe())
    {
        printf("此时系统不安全，系统推出");
        return 0;
    }
}