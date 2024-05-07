#include <stdio.h>
#define MAX_N 100
#define INFINITY 9999

int n, m, f, d[MAX_N], p[MAX_N], a[MAX_N][MAX_N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, y;
        scanf("%d%d%d%d", &u, &v, &w, &y);
        a[u][v] = a[v][u] = w + y;
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = INFINITY;
        p[i] = 0;
    }

    d[1] = 0;

    for (int i = 1; i <= n; i++)
    {

        int MIN = INFINITY, u;
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
                if (a[u][v] < d[v])
                {
                    d[v] = a[u][v];
                }
    }

    int total = 0;
    for (int i = 1; i <= n; i++)
    {

        total += d[i];
    }

    total += (n - 1) * 6;

    printf("%d", total);

    return 0;
}