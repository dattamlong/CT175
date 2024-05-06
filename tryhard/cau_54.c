#include <stdio.h>
#define maxn 9999
#define max(a, b) ((a) < (b) ? (b) : (a))
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 1][n + 1], b[n + 1], ra[n + 1];
  for (int i = 1; i <= n; i++) {
    b[i] = ra[i] = 0;
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;
  }
  for (int u = 1; u <= n; u++) {
    int v;
    do {
      scanf("%d", &v);
      if (v) {
        a[v][u] = 1;
        b[u]++;
      }
    } while (v);
  }

  int q[9999], f = -1, r = -1, k = 1;

  for (int u = 1; u <= n; u++) {
    if (!b[u]) {
      q[++r] = u;
      ra[u] = k;
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

  for (int u = 1; u <= n; u++)
    printf("HP%d: HK%d\n", u, ra[u] + 1);

  return 0;
}
