#include <stdio.h>

typedef struct {
  int x, y;
} point;
int a[8][8], cnt = 0;
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {-1, 1, -1, 1, 2, -2, 2, -2};

int isValid(point u) {
  if (u.x < 0 || u.y < 0 || u.x >= 8 || u.y >= 8)
    return 0;
  if (!a[u.y][u.x])
    return 0;
  return 1;
}

void dfs(point u) {
  if (!isValid(u))
    return;
  a[u.y][u.x] = 0;
  cnt--;
  for (int i = 0; i < 8; i++) {
    point v;
    v.x = u.x + dx[i];
    v.y = u.y + dy[i];
    dfs(v);
  }
}

int main() {
  point st;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 9) {
        st.y = i;
        st.x = j;
        a[i][j] = 1;
      }
      if (a[i][j])
        cnt++;
    }
  dfs(st);
  if (!cnt)
    printf("CO THE");
  else
    printf("KHONG THE");
}
