/* Cable master
 */

#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 10000
#define INF 99999999

// 入力
int N, K;
double L[MAX_N];

// 条件を満たすか判定
bool C(double x) {
  int num = 0;
  for (int i = 0; i < N; i++) {
    num += (int) (L[i] / x);
  }
  return num >= K;
}

int main(){
  // input
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  // 解の存在範囲を初期化
  double lb = 0, ub = INF;

  // 解の存在範囲が十分狭くなるまで繰り返す
  for (int i = 0; i < 100; i++) {
    double mid = (lb + ub) /2;
    if (C(mid)) lb = mid;
    else ub = mid;
  }

  cout << floor(ub * 100) / 100 << endl;

  return 0;
}
