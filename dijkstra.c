#include <stdio.h>
#define maxn 1000
#define oo 9999

int a[maxn][maxn], d[maxn], p[maxn], trace[maxn], b[maxn];
int m, n, start, end;

void solve()
{
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
            if (d[j] < MIN && !p[j])
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

    int count = 0;

    do
    {
        b[count++] = end;
        end = trace[end];
    } while (end != -1);

    while (count--)
    {
        printf("%d ", b[count]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = w;
        a[v][u] = w;
    }

    scanf("%d%d", &start, &end);

    solve();

    return 0;
}