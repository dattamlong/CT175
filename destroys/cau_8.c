#include <stdio.h>
#define maxn 1000

int n, m, x, u, v, b[maxn];

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        b[v]++;
        b[u]++;
    }

    scanf("%d", &x);

    printf("%d:%d", x, b[x]);
    return 0;
}