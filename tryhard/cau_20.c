#include <stdio.h>

int main() {
  int n, m, mx = -1, mxi = 1;
  scanf("%d%d", &n, &m);
  int a[n + 1];
  for (int i = 1; i <= n; i++)
    a[i] = 0;

  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u]++;
    if (a[u] > mx) {
      mx = a[u];
      mxi = u;
    } else if (a[u] == mx && u < mxi) {
      mxi = u;
    }
  }

  printf("%d has sent %d email(s).", mxi, mx);
}
