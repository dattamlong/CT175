#include <stdio.h>
#define maxn 1000
#define oo 9999

int a[maxn][maxn], d[maxn], p[maxn], trace[maxn], b[maxn];
int m, n;

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = oo;
        p[i] = 0;
    }

    d[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int u = 1, MIN = oo;
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
            if (a[u][v] != 0 && !p[v])
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
    printf("$%d", total);
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

    solve();

    return 0;
}