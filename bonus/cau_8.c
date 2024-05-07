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
            printf("%d ", i);
            q[++r] = i;
        }

    return 0;
}
