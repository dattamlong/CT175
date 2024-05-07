#include <stdio.h>
#define maxn 100

typedef struct
{
    int u, v, w;
} ed;

ed e[maxn];
int n, m, par[maxn], sumE;

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

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        sumE += e[i].w;
    }

    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 1; i < m; i++)
        for (int j = i + 1; j <= m; j++)
            if (e[i].w > e[j].w)
                swap(&e[i], &e[j]);

    int total = 0;

    for (int i = 1; i <= n; i++)
    {
        if (join(e[i].u, e[i].v))
        {
            total += e[i].w;
        }
    }

    printf("%d", sumE - total);

    return 0;
}