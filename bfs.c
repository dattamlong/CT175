#include <stdio.h>
#define maxn 1000

int n, m, f = -1, r = -1;
int a[maxn][maxn], cnt[maxn], color[maxn], q[maxn];

void bfs(int u)
{
    q[++r] = u;
    color[u] = 0;
    cnt[0] = 1;

    while (f < r)
    {
        int u = q[++f];

        for (int v = 1; v <= n; v++)
            if (a[u][v])
            {
                if (color[u] == color[v])
                {
                    cnt[0] = -1;
                    cnt[1] = -1;
                    return;
                }

                if (color[v] == -1)
                {
                    color[v] = !color[u];
                    cnt[color[v]]++;
                    q[++r] = v;
                }
            }
    }
}

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        color[i] = -1;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }

    for (int u = 1; u <= n; u++)
        if (color[u] == -1 && cnt[0] != -1)
            bfs(u);

    printf("%d %d", cnt[0], cnt[1]);

    return 0;
}