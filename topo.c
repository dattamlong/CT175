#include <stdio.h>
#define maxn 100

int n, m, a[maxn][maxn], b[maxn], d[maxn], q[maxn], f = -1, r = -1;

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%u", &u, &v);
        a[v][u] = 1;
        b[u]++;
    }

    for (int i = 1; i <= n; i++)
        if (!b[i])
        {
            d[i] = 1;
            q[++r] = i;
        }

    int maxd = 0;

    while (f < r)
    {
        int u = q[++f];

        for (int v = 1; v <= n; v++)
        {
            if (a[u][v])
            {
                b[v]--;
                if (!b[v])
                {
                    q[++r] = v;
                    d[v] = d[u] + 1;
                    if (maxd < d[v])
                        maxd = d[v];
                }
            }
        }
    }

    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += d[i];
    }

    printf("%d %d", total, maxd);

    return 0;
}