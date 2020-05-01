/* Face The Right Way
 * 反転
 */

#include <iostream>

using namespace std;

#define MAX_N 5000

// 入力
int N;
int dir[MAX_N]; // 牛の方向

int f[MAX_N]; // 区間[i, i+K-1]を反転させたかどうか

// Kを固定した時の最小操作奇数を求める
// 解が存在しないならば-1
int calc(int K){
  memset(f, 0, sizeof(f));
  int res = 0;
  int sum = 0; // fの和
  for(int i = 0; i + K <= N; i++){
    // 区間[i, i+K-1]に着目
    if((dir[i] + sum) % 2 != 0){
      // 先頭の牛が後ろを向いている
      res++;
      f[i] = 1;
    }
    sum += f[i];
    if(i - K + 1 >= 0){
      sum -= f[i - K + 1];
    }
  }

  // 残りの牛が前を向いているかチェック
  for(int i = N - K + 1; i < N; i++){
    if((dir[i] + sum) % 2 != 0){
      // 解なし
      return -1;
    }
    if(i - K + 1 >= 0){
      sum -= f[i - K + 1];
    }
  }
  return res;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> dir[i];
  }

  int K = 1, M = N;
  for(int k = 1; k <= N; k++){
    int m = calc(k);
    if(m >= 0 && M > m){
      M = m;
      K = k;
    }
  }

  cout << K << " " << M << endl;

  return 0;
}
