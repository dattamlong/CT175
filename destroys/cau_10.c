#include <stdio.h>
#define maxn 1000
#define oo 9999

int n, m, d[maxn], p[maxn];
int trace[maxn], a[maxn][maxn], start, end;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = a[v][u] = w;
    }

    scanf("%d%d", &start, &end);

    for (int i = 1; i <= n; i++)
    {
        d[i] = oo;
        p[i] = 0;
        trace[i] = -1;
    }

    d[start] = 0;

    for (int i = 1; i <= n; i++)
    {

        int u, MIN = oo;

        for (int j = 1; j <= n; j++)
        {
            if (!p[j] && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }

        p[u] = 1;

        for (int v = 1; v <= n; v++)
            if (d[u] + a[u][v] < d[v])
            {
                d[v] = d[u] + a[u][v];
                trace[v] = u;
            }
    }

    printf("%d\n", d[end]);

    int b[maxn], cnt = 0;

    do
    {
        b[cnt++] = end;
        end = trace[end];
    } while (end != -1);

    while (cnt--)
    {
        printf("%d ", b[cnt]);
    }

    return 0;
}