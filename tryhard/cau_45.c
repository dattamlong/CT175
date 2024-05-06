#include <stdio.h>
#define oo 99999
#define read(a) scanf("%d", &a)
#define read2(a, b) scanf("%d%d", &a, &b)
#define read3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define read4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define debug(a) fprintf(stderr, "#DEBUG: %s = %d\n", #a, a)

int main() {
  int n, m, flag = 1;
  read2(n, m);
  int b[n + 2][n + 2];
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++)
      b[i][j] = 0;

  int in_total = 0, out_total;
  for (int i = 0; i < m; i++) {
    int u, v, mx, r;
    read4(u, v, mx, r);
    b[u][v] = r;
    if (r > mx || r < 0)
      flag = 0;
    if (u == 0)
      out_total += r;
    if (v == n + 1)
      in_total += r;
  }
  if (out_total != in_total)
    flag = 0;
  for (int u = 1; u <= n; u++) {
    int s1 = 0, s2 = 0;
    for (int v = 0; v <= n + 1; v++) {
      s1 += b[u][v];
      s2 += b[v][u];
    }
    if (s1 != s2)
      flag = 0;
  }
  if (flag)
    printf("%d", in_total);
  else
    printf("KHONG HOP LE");
  return 0;
}
