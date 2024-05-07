#include <stdio.h>
#define maxn 1000
#define oo 9999

int n, a[maxn][maxn], u, v, b[maxn], c[maxn], d[maxn];
int D[maxn], P[maxn], f = -1, r = -1, rank[maxn], q[maxn];
int maxRank = 1, t[maxn], T[maxn];

int main()
{

    scanf("%d", &n);
    for (int u = 1; u <= n; u++)
    {
        scanf("%d", &d[u]);
        do
        {
            scanf("%d", &v);
            if (v > 0)
            {

                b[u]++;
                a[v][u] = 1;
            }
        } while (v > 0);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!b[i])
        {
            q[++r] = i;
            rank[i] = 1;
        }
    }

    // topo
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
                    rank[v] = rank[u] + 1;
                    if (maxRank < rank[v])
                        maxRank = rank[v];
                }
            }
        }
    }

    // luot di
    for (int i = 2; i <= maxRank; i++)
    {
        for (int j = 1; j <= n; j++)
            if (rank[j] == i)
            {
                for (int k = 1; k <= n; k++)
                    if (a[k][j])
                    {
                        if (t[j] < t[k] + d[k])
                        {
                            t[j] = t[k] + d[k];
                            T[j] = t[j];
                        }
                    }
            }
    }

    // luot ve
    for (int i = maxRank - 1; i >= 1; i--)
    {

        for (int j = 1; j <= n; j++)
            if (rank[j] == i)
            {
                T[j] = oo;
                for (int k = 1; k <= n; k++)
                {
                    if (a[j][k])
                    {

                        if (T[j] > T[k] - d[j])
                        {
                            T[j] = T[k] - d[j];
                        }
                    }
                }
            }
    }

    for (int i = 1; i <= n + 2; i++)
        if (t[i] == T[i])
            printf("%d\n", i);

    return 0;
}