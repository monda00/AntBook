/* 01ナップサック問題その２
 * サイズ制約が変わったもの（重さに比べて価値が小さい）
 * 動的計画法
 * 価値に対する最小の重さをDPで計算する
 */

#include <iostream>
#include <vector>

#define MAX_V 100
#define INF INT_MAX

using namespace std;

int main(){
  int n, W;
  cin >> n >> W;
  vector<int> w(n);
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> w[i] >> v[i];
  }
  vector<vector<int> > dp(n, vector<int>(n * MAX_V + 1, INF));

  dp[0][0] = 0;

  // 品物iに対して
  for(int i = 0; i < n; i++){
    // 重さjまで
    for(int j = 0; j <= n * MAX_V; j++){
      if(j < v[i]){
        dp[i + 1][j] = dp[i][j];
      } else {
        // 重さが小さい方を選ぶ
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= n * MAX_V; i++){
    // 条件を満たす最大のj（ここではiだが）が解になる
    if(dp[n][i] <= W){
      ans = i;
    }
  }

  cout << ans << endl;

  return 0;
}
