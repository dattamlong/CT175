#include <stdio.h>
#define oo 99999
#define read(a) scanf("%d", &a)
#define read2(a, b) scanf("%d%d", &a, &b)
#define read3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define read4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define debug(a) fprintf(stderr, "#DEBUG: %s = %d\n", #a, a)

int main() {
  int n, m;
  read2(n, m);
  int a[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    read3(u, v, w);
    a[u][v] = w;
    a[v][u] = w;
  }
  int st, fi, budget;
  read3(st, fi, budget);

  int D[n + 1], P[n + 1];
  for (int i = 1; i <= n; i++) {
    D[i] = oo;
    P[i] = 0;
  }
  D[st] = 0;

  for (int i = 1; i <= n; i++) {
    int uBest, Max = oo;
    for (int u = 1; u <= n; u++)
      if (D[u] < Max && !P[u]) {
        uBest = u;
        Max = D[u];
      }

    int u = uBest;
    P[u] = 1;
    for (int v = 1; v <= n; v++) {
      if (a[u][v]) {
        if (D[v] > D[u] + a[u][v]) {
          D[v] = D[u] + a[u][v];
        }
      }
    }
  }
  if (D[fi] > budget) {
    printf("KHONG DI DUOC");
  } else
    printf("%d", budget - D[fi]);

  return 0;
}
