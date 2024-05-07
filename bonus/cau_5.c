#include <stdio.h>
#define maxn 100
#define oo 9999

int n, m, f, d[maxn], p[maxn], a[maxn][maxn], start, end;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = a[v][u] = w;
    }

    scanf("%d", &start);

    for (int i = 1; i <= n; i++)
    {
        d[i] = oo;
        p[i] = 0;
    }

    d[start] = 0;

    for (int i = 1; i <= n; i++)
    {

        int MIN = oo, u;
        for (int j = 1; j <= n; j++)
        {
            if (d[j] < MIN && !p[j])
            {
                MIN = d[j];
                u = j;
            }
        }

        p[u] = 1;

        for (int v = 1; v <= n; v++)
            if (a[u][v] && !p[v])
                if (d[u] + a[u][v] < d[v])
                {
                    d[v] = d[u] + a[u][v];
                }
    }

    int MAX = -1;

    for (int i = 1; i <= n; i++)
    {

        if (d[i] == oo)
        {
            printf("KHONG THE DI");
            return 0;
        }
        if (MAX < d[i])
            MAX = d[i];
    }

    printf("%d", MAX);

    return 0;
}