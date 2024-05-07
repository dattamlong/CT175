#include <stdio.h>
#define maxn 100

int n, m, check = 1, a[maxn][maxn], vi[maxn];

void dfs(int u)
{
    vi[u] = 1;
    for (int v = 1; v <= n; v++)
        if (a[u][v])
        {
            if (!vi[v])
                dfs(v);
            else if (vi[v] == 1)
                check = 0;
        }
    vi[u] = 2;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (!vi[i])
            dfs(i);

    if (check)
        printf("HOP LE");
    else
        printf("KHONG");

    return 0;
}