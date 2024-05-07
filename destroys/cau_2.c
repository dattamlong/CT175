#include <stdio.h>
#define maxn 100

int n, m, x, y, cnt;
int b[maxn], a[maxn][maxn];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }

    scanf("%d%d", &x, &y);

    for (int i = 1; i <= n; i++)
    {
        if ((a[i][x] || a[x][i]) && (a[i][y] || a[y][i]))
        {
            b[++cnt] = i;
        }
    }

    if (!cnt)
        printf("KHONG CHUNG DOI THU");
    else
        for (int i = 1; i <= cnt; i++)
            printf("%d ", b[i]);

    return 0;
}