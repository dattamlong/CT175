#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int k;
      scanf("%d", &k);
      if (k)
        printf("%d has sent %d email(s) to %d.\n", i, k, j);
    }
}
