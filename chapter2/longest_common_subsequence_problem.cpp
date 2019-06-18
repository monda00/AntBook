/* 動的計画法
 */

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<char> s;
vector<char> t;
vector<vector<int> > dp;

int main(){
  cin >> n >> m;
  s = vector<char>(n);
  t = vector<char>(m);
  dp = vector<vector<int> >(n+1, vector<int>(m+1, 0));
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  for(int i = 0; i < m; i++){
    cin >> t[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(s[i] == t[j]){
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
