/* Crazy Rows
 */

#include <iostream>
#include <utility>

using namespace std;

#define MAX_N 40

// 入力
int N;
int M[MAX_N][MAX_N]; // 行列

int a[MAX_N]; // a[i]はi行めの最後に現れる1の位置

int main(){
  int res = 0;

  // 入力
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> M[i][j];
    }
  }

  // 最後に現れる1の位置を計算
  for(int i = 0; i < N; i++){
    a[i] = -1; // i行目に1がない場合は-1にしておく
    for(int j = 0; j < N; j++){
      if(M[i][j] == 1) a[i] = j;
    }
  }

  for(int i = 0; i < N; i++){
    // 移動する行を計算
    int pos = -1; // i行目に移動する行
    for(int j = i; j < N; j++){
      if(a[j] <= i){
        pos = j;
        break;
      }
    }
    // 実際にスワップする
    for(int j = pos; j > i; j--){
      swap(a[j], a[j - 1]);
      res++;
    }
  }

  cout << res << endl;

  return 0;
}
