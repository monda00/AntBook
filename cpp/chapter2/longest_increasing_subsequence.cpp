/* 最長増加部分列問題
 * 動的計画法
 * dp[i] := 最後がa_iであるような最長の増加部分列の長さ
 * dp[i] := 長さがi+1であるような増加部分列における最終要素の最小値
 */

#include <iostream>
#include <vector>

using namespace std;

#define INF INT_MAX

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<int> dp(n);

  int ans = 0;
  for(int i = 0; i < n; i++){
    dp[i] = 1;
    for(int j = 0; j < i; j++){
      if(a[j] < a[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }

  cout << ans << endl;

  dp = vector<int>(n, INF);
  for(int i = 0; i < n; i++){
    *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }

  cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;

  return 0;
}
