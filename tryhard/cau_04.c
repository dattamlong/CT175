#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int g[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &g[i][j]);
    }
  }

  int k, ans = 0;
  scanf("%d", &k);
  for (int i = 1; i <= n; i++)
    ans += g[i][k];
  printf("%d:%d", k, ans);
}
