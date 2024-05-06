#include <stdio.h>
#define oo 99999
#define maxn 1000
#define read(a) scanf("%d", &a)
#define read2(a, b) scanf("%d%d", &a, &b)
#define read3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define read4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define debug(a) fprintf(stderr, "#DEBUG: %s = %d\n", #a, a)

int color[maxn], a[maxn][maxn];
int n, m, q[9999], f = -1, r = -1, cnt[2] = {0, 0}, u, v;

void bfs(int u) {
  q[++r] = u;
  color[u] = 0;
  cnt[0]++;

  while (f < r) {
    int u = q[++f];
    for (int v = 1; v <= n; v++) {
      if (a[u][v]) {
        if (color[u] == color[v]) {
          cnt[0] = cnt[1] = -1;
          return;
        } else if (color[v] == -1) {
          color[v] = !color[u];
          cnt[color[v]]++;
          q[++r] = v;
        }
      }
    }
  }
}

int main() {
  read2(n, m);
  for (int i = 1; i <= n; i++) {
    color[i] = -1;
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;
  }
  for (int i = 0; i < m; i++) {
    read2(u, v);
    a[u][v] = a[v][u] = 1;
  }

  for (int u = 1; u <= n; u++)
    if (color[u] == -1 && cnt[0] != -1)
      bfs(u);

  printf("%d %d", cnt[0], cnt[1]);

  return 0;
}
