/* 平均最大化
 * 二分探索
 * C(x) = 単位重さあたりの価値がx以上となるように選ぶことができる
 */

#include <iostream>

using namespace std;

#define MAX_N 10000
#define INF 9999999

// 入力
int n, k;
int w[MAX_N], v[MAX_N];

double y[MAX_N]; // v - x * w

// 条件を満たすか判定
bool C(double x){
  for (int i = 0; i < n; i++) {
    y[i] = v[i] - x * w[i];
  }
  sort(y, y + n);

  // yの大きい方からk個の和を計算
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += y[n - i - 1];
  }

  return sum >= 0;
}

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }

  double lb = 0, ub = INF;
  for (int i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (C(mid)) lb = mid;
    else ub = mid;
  }

  cout << ub << endl;

  return 0;
}
