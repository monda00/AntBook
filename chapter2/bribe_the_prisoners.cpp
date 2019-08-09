/* Bribe the Prisoners
 */

#include <iostream>

using namespace std;

#define MAX_Q 100

// 入力
int P, Q, A[MAX_Q + 2]; // Aには1-indexedでデータが入っている

// dp[i][j] := (i, j)を解放するのに必要な金貨
int dp[MAX_Q + 1][MAX_Q + 2];

int main(){
  cin >> P >> Q;
  for(int i = 1; i <= Q; i++){
    cin >> A[i];
  }
  // 簡単のため、端をAに追加する
  A[0] = 0;
  A[Q + 1] = P + 1;

  // 初期化
  for(int q = 0; q <= Q; q++){
    dp[q][q + 1] = 0;
  }

  // 端が小さい順にdpを埋めていく
  for(int w = 2; w <= Q + 1; w++){
    cout << "w = " << w << endl;
    for(int i = 0; i + w <= Q + 1; i++){
      cout << "i = " << i << endl;
      // dp[i][j]を計算
      int j = i + w, t = INT_MAX;

      // 最初に解放する主審を全て試し、最小のコストのものを探す
      for(int k = i + 1; k < j; k++){
        cout << "k = " << k << endl;
        t = min(t, dp[i][k] + dp[k][j]);
      }

      // 最初の解放では解放する囚人に関わらずA[j] - A[i] - 2の金貨が必要
      dp[i][j] = t + A[j] - A[i] - 2;
      cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }

  cout << dp[0][Q + 1] << endl;

  return 0;
}
