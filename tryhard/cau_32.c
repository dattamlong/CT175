
#include <stdio.h>
#define maxn 1000
typedef struct {
  int u, v, w;
} edge;

int n, m, par[maxn];
edge g[maxn];

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
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    par[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d%d%d", &g[i].u, &g[i].v, &x, &y);
    g[i].w = x + y;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (g[j].w > g[i].w) {
        edge t = g[i];
        g[i] = g[j];
        g[j] = t;
      }
    }
  }

  int total = 0;
  for (int i = 0; i < m; i++) {
    // printf("%d %d %d\n", g[i].u, g[i].v, g[i].w);
    if (join(g[i].u, g[i].v)) {
      total += g[i].w;
    }
  }

  printf("%d", total);
  return 0;
}
