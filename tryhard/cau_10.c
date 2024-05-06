#include <stdio.h>
#define oo 99999
#define read(a) scanf("%d", &a)
#define read2(a, b) scanf("%d%d", &a, &b)
#define read3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define read4(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define debug(a) fprintf(stderr, "#DEBUG: %s = %d\n", #a, a)

int n, m;

int main() {
  read2(n, m);
  int P[n + 1], D[n + 1], trace[n + 1], W[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    P[i] = 0;
    D[i] = oo;
    trace[i] = -1;
    for (int j = 1; j <= n; j++)
      W[i][j] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    read3(u, v, w);
    W[u][v] = w;
    W[v][u] = w;
  }
  int st, fi;
  read2(st, fi);
  D[st] = 0;

  for (int i = 1; i <= n; i++) {
    int uBest, Max = oo;
    for (int u = 1; u <= n; u++) {
      if (D[u] < Max && !P[u]) {
        uBest = u;
        Max = D[u];
      }
    }

    int u = uBest;
    P[u] = 1;
    for (int v = 1; v <= n; v++) {
      if (W[u][v]) {
        if (D[v] > D[u] + W[u][v]) {
          D[v] = D[u] + W[u][v];
          trace[v] = u;
        }
      }
    }
  }

  int stack[9999], k = -1;

  printf("%d\n", D[fi]);
  do {
    stack[++k] = fi;
    fi = trace[fi];
  } while (fi != -1);

  for (int i = k; i >= 0; i--)
    printf("%d ", stack[i]);
}
