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
    a[v]++;
    if (a[v] > mx) {
      mx = a[v];
      mxi = v;
    } else if (a[v] == mx && v < mxi) {
      mxi = v;
    }
  }

  printf("%d has received %d email(s).", mxi, mx);
}
