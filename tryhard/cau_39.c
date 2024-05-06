#include <stdio.h>
#define maxn 1000

int n, m, check = 0, st, fi;
int g[maxn][maxn], mark[maxn];

void dfs(int u) {
  mark[u] = 1;
  for (int i = 1; i <= n; i++) {
    if (g[u][i]) {
      if (!mark[i])
        dfs(i);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      g[i][j] = 0;
    mark[i] = 0;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u][v] = 1;
    g[v][u] = 1;
  }
  scanf("%d%d", &st, &fi);
  dfs(st);
  if (mark[fi]) {
    printf("DUOC");
  } else {
    printf("KHONG");
  }
}
