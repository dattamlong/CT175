#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++)
    a[i] = b[i] = 0;

  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u]++;
    b[v]++;
  }
  int k;
  scanf("%d", &k);
  printf("%d %d", a[k], b[k]);
}
