#include <stdio.h>
#define maxn 100

typedef struct
{
    int u, v, w;
} ed;

int par[maxn];
int n, m, total = 0, x, y;
ed e[maxn];

int findRoot(int u)
{
    if (par[u] == u)
        return u;
    return (par[u] = findRoot(par[u]));
}

int join(int x, int y)
{
    int u = findRoot(x);
    int v = findRoot(y);

    if (u == v)
        return 0;

    par[v] = u;
    return 1;
}

void swap(ed *a, ed *b)
{
    ed temp = *a;
    *a = *b;
    *b = temp;
}

void solve()
{
    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 1; i < m; i++)
        for (int j = i + 1; j <= m; j++)
            if (e[i].w > e[j].w)
                swap(&e[i], &e[j]);

    for (int i = 1; i <= m; i++)
        if (join(e[i].u, e[i].v))
        {
            total += e[i].w;
        }

    int co = par[1];

    for (int i = 1; i <= n; i++)
        if (par[i] != co)
        {
            co = -1;
            break;
        }

    if (co == -1)
        printf("KHONG CO LOI GIAI");
    else
        printf("%d", total);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &e[i].u, &e[i].v, &x, &y);
        e[i].w = x * y;
    }

    solve();
    return 0;
}