#include <stdio.h>
#define oo 99999
#define read(a) scanf("%d", &a)
#define read2(a, b) scanf("%d%d", &a, &b)
#define read3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define read4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define debug(a) fprintf(stderr, "#DEBUG: %s = %d\n", #a, a)

#define maxn 1000
int n, m;
int par[maxn];

int find(int u) {
  if (par[u] == u)
    return u;
  return find(par[u]);
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
  read2(n, m);
  for (int i = 1; i <= n; i++)
    par[i] = i;
  while (m--) {
    int u, v;
    read2(u, v);
    join(u, v);
  }
  for (int i = 2; i <= n; i++)
    if (find(i) != find(i - 1)) {
      printf("KHONG");
      return 0;
    }

  printf("DUOC");
  return 0;
}
