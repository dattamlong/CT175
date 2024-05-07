#include <stdio.h>
#define maxn 2000

int f = -1, r = -1, n, m, a[maxn][maxn], d[maxn], b[maxn], q[maxn];

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!a[u][v])
        {
            a[u][v] = 1;
            b[v]++;
        }
    }

    for (int i = 1; i <= n; i++)
        if (!b[i])
        {
            d[i] = 1;
            q[++r] = i;
        }

    // bfs
    int MAX = -1;

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
                    if (MAX < d[v])
                        MAX = d[v];
                }
            }
        }
    }

    for (int i = 1; i <= MAX; i++)
        for (int j = 1; j <= n; j++)
            if (d[j] == i)
                printf("%d\n", j);

    return 0;
}
