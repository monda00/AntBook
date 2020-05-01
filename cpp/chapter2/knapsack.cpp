/* 動的計画法
 * ナップサック問題
 */
#include <iostream>
#include <vector>

using namespace std;

int n, W;
vector<int> w, v;

// 愚直なやり方
int simpleAlg(int i, int j){
  int res;
  if(i == n){
    // もう品物は残っていない
    res = 0;
  } else if (j < w[i]){
    // この品物は入らない
    res = simpleAlg(i + 1, j);
  } else {
    // 入れない場合と入れる場合を両方試す
    res = max(simpleAlg(i + 1, j), simpleAlg(i + 1, j - w[i]) + v[i]);
  }
  return res;
}

// 計算時の結果を残す
vector<vector<int> > dp;
// メモ化
int simpleAlgEx(int i, int j){
  if(dp[i][j] >= 0){
    // すでに調べたことがあるならばその結果を利用
    return dp[i][j];
  }

  int res;
  if(i == n){
    res = 0;
  } else if(j < w[i]){
    res = simpleAlgEx(i + 1, j);
  } else {
    res = max(simpleAlgEx(i + 1, j), simpleAlgEx(i + 1, j - w[i]) + v[i]);
  }

  // 結果をテーブルに記憶する
  return dp[i][j] = res;
}

int main(){
  cin >> n >> W;
  w = vector<int>(n);
  v = vector<int>(n);
  for(int i = 0; i < n; i++){
    cin >> w[i] >> v[i];
  }

  cout << simpleAlg(0, W) << endl;

  // メモ化テーブル
  dp = vector<vector<int> >(n+1, vector<int>(W+1, -1));
  cout << simpleAlgEx(0, W) << endl;

  return(0);
}

