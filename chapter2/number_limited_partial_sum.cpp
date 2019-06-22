/* 個数制限付き部分和問題
 * 動的計画法
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  vector<int> m(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> m[i];
  }

  vector<vector<bool> > dp(n+1, vector<bool>(K+1, false));

  // dp[i+1][j] := i番目まででjが作れるか
  // boolのDPは無駄があることが多い
  // 同じ計算量でもっと多くのことを知れる
  dp[0][0] = true;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= K; j++){
      for(int k = 0; k <= m[i] && k * a[i] <= j; k++){
        dp[i + 1][j] = dp[i + 1][j] | dp[i][j - k * a[i]];
      }
    }
  }

  if(dp[n][K]){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  // dp[i+1][j] := i番目まででjを作る際に余る最大のi番目の個数（作れないときは-1）
  vector<int> dp2(K + 1, -1);

  dp2[0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= K; j++){
      if(dp2[j] >= 0){
        dp2[j] = m[i];
      } else if(j < a[i] || dp2[j - a[i]] <= 0){
        dp2[j] = -1;
      } else {
        dp2[j] = dp2[j - a[i]] - 1;
      }
    }
  }

  if(dp2[K] >= 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

