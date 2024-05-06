#include <stdio.h>
#define maxn 1000

int n;
int g[maxn][maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  int u, v;
  scanf("%d%d", &u, &v);

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == u || i == v)
      continue;
    if (!g[u][i] && !g[i][u])
      continue;
    if (!g[v][i] && !g[i][v])
      continue;
    cnt++;
    printf("%d ", i);
  }

  if (!cnt)
    printf("KHONG CHUNG DOI THU");
}
