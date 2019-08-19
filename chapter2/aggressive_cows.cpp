/* Aggressive cows
 * 二分探索
 */

#include <iostream>

using namespace std;

#define MAX_N 100000
#define INF 9999999

// 入力
int N, M;
int x[MAX_N];

// 条件を満たすか判定
bool C(int d) {
  int last = 0;
  for (int i = 1; i < M; i++) {
    int crt = last + 1;
    while (crt < N && x[crt] - x[last] < d) {
      crt++;
    }
    if (crt == N) return false;
    last = crt;
  }
  return true;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }

  // 最初にソート
  sort(x, x + N);

  // 解の存在範囲を初期化
  int lb = 0, ub = INF;

  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (C(mid)) lb = mid;
    else ub = mid;
  }

  cout << lb << endl;

  return 0;
}
