/* 重複組み合わせ
 * 動的計画法
 * dp[i + 1][j] := i番目までの品物からj個選ぶ組み合わせの総数
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m, M;
  cin >> n >> m >> M;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

  for(int i = 0; i <= n; i++){
    dp[i][0] = 1;
  }
  for(int i = 0; i < n; i++){
    for(int j = 1; j <=m; j++){
      if(j - 1 - a[i] >= 0){
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
      }
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
