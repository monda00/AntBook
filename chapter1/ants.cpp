#include <cstdio>
#include <algorithm>

int MAX_N = 100000;

int main() {
  int L, n;
  int x[MAX_N];

  scanf("%d %d", &L, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  int minT = 0;
  int maxT = 0;
  for (int i = 0; i < n; i++) {
    minT = std::max(minT, std::min(x[i], L - x[i]));
    maxT = std::max(maxT, std::max(x[i], L - x[i]));
  }

  printf("%d %d", minT, maxT);
}
