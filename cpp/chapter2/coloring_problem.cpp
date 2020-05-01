/* 彩色問題
 * 二部グラフ判定
 * 隣接リスト
 */

#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 1000

vector<int> G[MAX_V];
int V;

int color[MAX_V];

bool dfs(int v, int c){
  color[v] = c;
  for(int i = 0; i < G[v].size(); i++){
    // 隣の頂点が同じ色なら
    if(color[G[v][i]] == c) return false;
    // 隣がまだ塗られていないなら-cで塗る
    if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
  }
  return true;
}

int main(){
  cin >> V;
  int E;
  cin >> E;
  for(int i = 0; i < 2 * E; i++){
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }

  for(int i = 0; i < V; i++){
    if(color[i] == 0){
      if(!dfs(i, 1)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}
