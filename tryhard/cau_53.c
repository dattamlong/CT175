#include <stdio.h>
#define oo 99999
#define read(a) scanf("%d", &a)
#define read2(a, b) scanf("%d%d", &a, &b)
#define read3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define read4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define debug(a) fprintf(stderr, "#DEBUG: %s = %d\n", #a, a)
#define maxn 1000

int q[9999], f = -1, r = -1;
int n, m;
int a[maxn][maxn], deg[maxn], rank[maxn];

int main() {
  read2(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;
    deg[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    read2(u, v);
    if (!a[u][v]) {
      deg[v]++;
      a[u][v] = 1;
    }
  }
  for (int u = 1; u <= n; u++)
    if (!deg[u]) {
      q[++r] = u;
      rank[u] = 0;
    }

  while (f != r) {
    int u = q[++f];
    for (int v = 1; v <= n; v++)
      if (a[u][v]) {
        deg[v]--;
        if (!deg[v]) {
          q[++r] = v;
          rank[v] = rank[u] + 1;
        }
      }
  }

  for (int i = 0; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      if (rank[u] == i)
        printf("%d ", u);
    }
  }
  return 0;
}
