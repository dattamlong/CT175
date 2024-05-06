#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n + 1];
  for (int i = 1; i <= n; i++)
    a[i] = 0;

  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u]++;
    a[v]++;
  }
  for (int i = 1; i <= n; i++)
    printf("%d\n", a[i]);
}
