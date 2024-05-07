#include <stdio.h>

int a[1000][1000], n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v]++;
        a[v][u]++;
    }

    int x, y;
    scanf("%d%d", &x, &y);

    if (!a[x][y])
        printf("HAY CHAO NHAU DI");

    else
        printf("%d", a[x][y]);

    return 0;
}