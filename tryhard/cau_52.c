
#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n + 1][n + 1], b[n + 1], ra[n + 1];
  for (int i = 1; i <= n; i++) {
    b[i] = 0;
    ra[i] = 0;
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[v][u] = 1;
    b[u]++;
  }

  int q[9999], f = -1, r = -1;

  for (int u = 1; u <= n; u++) {
    if (!b[u]) {
      q[++r] = u;
      ra[u] = 1;
    }
  }
  while (f != r) {
    int u = q[++f];
    for (int v = 1; v <= n; v++) {
      if (a[u][v]) {
        b[v]--;
        if (!b[v]) {
          q[++r] = v;
          ra[v] = ra[u] + 1;
        }
      }
    }
  }

  int total = 0, mx = -1;
  for (int u = 1; u <= n; u++) {
    total += ra[u];
    if (ra[u] > mx)
      mx = ra[u];
  }

  printf("%d %d", total, mx);
  return 0;
}
