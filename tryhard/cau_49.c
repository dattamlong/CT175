#include <stdio.h>
#define maxn 100
#define oo 9999999

int D[maxn][maxn];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      D[i][j] = oo;

  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    D[u][v] = w;
    D[v][u] = w;
  }

  for (int k = 1; k <= n; k++)
    for (int u = 1; u <= n; u++)
      for (int v = 1; v <= n; v++) {
        if (u == v)
          continue;
        if (D[u][v] > D[u][k] + D[k][v]) {
          D[u][v] = D[u][k] + D[k][v];
        }
      }
  int u;
  scanf("%d", &u);
  int mx = -1, mxv = -1;
  for (int v = 1; v <= n; v++) {
    // printf("D[%d][%d] = %d\n", u, v, D[u][v]);
    if (D[u][v] != oo) {
      if (mx < D[u][v]) {
        mx = D[u][v];
        mxv = v;
      }
    }
  }

  printf("%d %d", mx, mxv);
}
