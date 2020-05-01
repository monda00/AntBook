/* 個数制限なしナップサック問題
 * 動的計画法
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, W;
  cin >> n >> W;
  vector<int> w(n);
  vector<int> v(n);

  for(int i = 0; i < n; i++){
      cin >> w[i] >> v[i];
  }

  vector<vector<int> > dp(n+1, vector<int>(W+1, 0));

  // シンプルに
  // 品物iに対して
  for(int i = 0; i < n; i++){
    // 重さはjまで
    for(int j = 0; j <= W; j++){
      // 品物iをk個使う
      for(int k = 0; k * w[i] <= j; k++){
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
      }
    }
  }

  cout << dp[n][W] << endl;

  // 改良版
  // 品物iに対して
  for(int i = 0; i < n; i++){
    // 重さはjまで
    for(int j = 0; j <= W; j++){
      if(j < w[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        // 品物iの重さを引いた価値と品物iの価値を合わせる（再利用）
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }

  cout << dp[n][W] << endl;

  return 0;
}
