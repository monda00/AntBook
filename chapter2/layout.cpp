/* Layout
 * ベルマンフォード法
 */

#include <iostream>

using namespace std;

#define MAX_ML 10000
#define MAX_MD 1000000
#define MAX_N 1000
#define INF 9999999

// 入力
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAX_N]; // 最短距離
bool updated; // 更新されたか

void update(int& x, int y){
  if(x > y){
    x = y;
    updated = true;
  }
}

// ベルマンフォード法によりdを計算する
void bellmanford(){
  for(int k = 0; k <= N; k++){
    updated = false;
    // i + 1からiへのコスト0
    for(int i = 0; i + 1 < N; i++){
      if(d[i + 1] < INF) update(d[i], d[i + 1]);
    }
    // ALからBLへコストDL
    for(int i = 0; i < ML; i++){
      if(d[AL[i] - 1] < INF) update(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
    }
    // BDからADへコスト-DD
    for(int i = 0; i < MD; i++){
      if(d[BD[i] - 1] < INF) update(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
    }
  }
}

int main(){
  cin >> N >> ML >> MD;
  for(int i = 0; i < ML; i++){
    cin >> AL[i] >> BL[i] >> DL[i];
  }
  for(int i = 0; i < MD; i++){
    cin >> AD[i] >> BD[i] >> DD[i];
  }

  // 閉路チェック
  fill(d, d + N, 0);
  bellmanford();
  if(updated){
    cout << -1 << endl;
    return 0;
  }

  fill(d, d + N, INF);
  d[0] = 0;
  bellmanford();
  int res = d[N -1];
  if(res == INF) res = -2;
  cout << res << endl;

  return 0;
}
