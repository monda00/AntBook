/* Fliptile
 * 反転
 */

#include <iostream>

using namespace std;

#define MAX_N 15
#define MAX_M 15

// 隣接するマスの座標
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

// 入力
int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N]; // 最適解保存用
int flip[MAX_M][MAX_N]; // 作業用

// (x, y)の色を調べる
int get(int x, int y){
  int c = tile[x][y];
  for(int d = 0; d < 5; d++){
    int x2 = x + dx[d], y2 = y + dy[d];
    if(0 <= x2 && x2 < M && 0 <= y2 && y2 < N){
      c += flip[x2][y2];
    }
  }
  return c % 2;
}

// １行目を決めた場合の最小操作回数を求める
// 解が存在しないなら-1
int calc(){
  // ２行目からのひっくり返し方を求める
  for(int i = 1; i < M; i++){
    for(int j = 0; j < N; j++){
      if(get(i - 1, j) != 0){
        // (i - 1, j)が黒色ならこのマスをひっくり返すしかない
        flip[i][j] = 1;
      }
    }
  }

  // 最後の行が全部白ならチェック
  for(int j = 0; j < N; j++){
    if(get(M - 1, j) != 0){
      // 解なし
      return -1;
    }
  }

  // 反転回数をカウント
  int res = 0;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      res += flip[i][j];
    }
  }

  return res;
}

int main(){
  cin >> M >> N;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cin >> tile[i][j];
    }
  }

  int res = -1;

  // １行目を辞書順で全通り試す
  for(int i = 0; i < 1 << N; i++){
    memset(flip, 0, sizeof(flip));
    for(int j = 0; j < N; j++){
      flip[0][N - j -1] = i >> j & 1;
    }
    int num = calc();
    if(num >= 0 && (res < 0 || res > num)){
      res = num;
      memcpy(opt, flip, sizeof(flip));
    }
  }

  if(res < 0){
    // 解なし
    cout << "IMPOSSIBLE" << endl;
  } else {
    for(int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        cout << opt[i][j];
        if (j + 1 == N) cout << endl;
        else cout << ' ';
      }
    }
  }

  return 0;
}
