#include <stdio.h>
#define maxn 1000

int n, a[maxn][maxn], b[maxn];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
            {
                b[j]++;
            }
        }

    int x;
    scanf("%d", &x);
    printf("%d:%d", x, b[x]);

    return 0;
}