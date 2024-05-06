#include <stdio.h>
#define maxn 1000

typedef struct {
  int u, v;
} edge;

int n, m, cir = 0;
int visit[maxn];
int g[maxn][maxn];

void dfs(int u) {
  visit[u] = 1;
  for (int i = 1; i <= n; i++)
    if (g[u][i]) {
      if (visit[i] == 0)
        dfs(i);
      else if (visit[i] == 1)
        cir = 1;
    }
  visit[u] = 2;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    visit[i] = 0;
    for (int j = 1; j <= n; j++)
      g[i][j] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u][v] = 1;
  }

  for (int i = 1; i <= n; i++)
    if (!visit[i])
      dfs(i);

  if (!cir)
    printf("HOP LE");
  else
    printf("KHONG");
  return 0;
}
