#include <stdio.h>
#define maxn 100

int n, m, a[maxn][maxn], vi[maxn], b[maxn], cnt = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(int u)
{

    b[++cnt] = u;

    vi[u] = 1;

    for (int v = 1; v <= n; v++)
        if (a[u][v] && !vi[v])
            dfs(v);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }

    int x;
    scanf("%d", &x);

    dfs(x);

    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            if (b[i] > b[j])
                swap(&b[i], &b[j]);

    while (cnt)
    {
        printf("%d ", b[cnt--]);
    }

    return 0;
}