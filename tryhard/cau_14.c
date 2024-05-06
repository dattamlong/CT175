#include <stdio.h>
#define maxn 1000

int n, par[maxn];

int find(int u) {
  if (par[u] == u)
    return u;
  return par[u] = find(par[u]);
}

int join(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return 0;
  par[v] = u;
  return 1;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    par[i] = i;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    join(u, v);
  }
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= n; i++) {
    if (find(k) == find(i))
      printf("%d ", i);
  }
}
