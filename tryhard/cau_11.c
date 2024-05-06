#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n + 1][n + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;

  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u][v]++;
    a[v][u]++;
  }
  int u, v;
  scanf("%d%d", &u, &v);
  if (a[u][v])
    printf("%d", a[u][v]);
  else
    printf("HAY CHAO NHAU DI");
}
