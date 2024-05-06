#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt[n + 1];
  for (int i = 1; i <= n; i++)
    cnt[i] = 0;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    cnt[v]++;
  }
  int k;
  scanf("%d", &k);
  printf("%d:%d", k, cnt[k]);
}
