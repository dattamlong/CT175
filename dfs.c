#include <stdio.h>
#define maxn 100

int a[maxn][maxn], vi[maxn];
int n, m, u, v, check = 1;

void dfs(int u)
{
    vi[u] = 1;
    for (int v = 1; v <= n; v++)
        if (a[u][v] == 1)
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
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
    }

    for (int u = 1; u <= n; u++)
        if (!vi[u])
            dfs(u);

    if (check)
        printf("HOP LE");
    else
        printf("KHONG");

    return 0;
}