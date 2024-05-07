#include <stdio.h>
#define maxn 1000

typedef struct
{
    int u, v, w;
} ed;

ed e[maxn];
int m, n, x, y, total, par[maxn];

void swap(ed *a, ed *b)
{
    ed temp = *a;
    *a = *b;
    *b = temp;
}

int findRoot(int u)
{

    if (par[u] == u)
        return u;

    return par[u] = findRoot(par[u]);
}

int join(int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);
    if (u == v)
        return 0;

    par[v] = u;
    return 1;
}

void solve()
{

    for (int i = 1; i <= n; i++)
        par[i] = i;

    // sort

    for (int i = 1; i < m; i++)
        for (int j = i + 1; j <= m; j++)
            if (e[i].w > e[j].w)
            {
                swap(&e[i], &e[j]);
            }

    for (int i = 1; i <= m; i++)
        if (join(e[i].u, e[i].v))
        {
            total += e[i].w;
        }

     int check = 1;

    for (int i = 1; i <= n; i++)
        if (par[i] != par[n])
            check = 0;

    if (check)
        printf("%d", total);
    else
        printf("KHONG CO LOI GIAI");
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