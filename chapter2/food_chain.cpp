/* 食物連鎖
 * Union-Find木
 */

#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> parent; // parent[i]:iの親

  UnionFind(int N) : parent(N) { // 最初は全て根として初期化
    for(int i = 0; i < N; i++) parent[i] = i;
  }

  int root(int x){ // データxが属する木の根を再帰で取得
    if(parent[x] == x) return x;
    return parent[x] = root(parent[x]);
  }

  void unite(int x, int y){ // xとyの木を併合
    int root_x = root(x);
    int root_y = root(y);
    if(root_x == root_y) return;
    parent[root_x] = root_y;
  }

  bool same(int x, int y){ // 2つのデータx、yが同じ木か
    int root_x = root(x);
    int root_y = root(y);
    return root_x == root_y;
  }
};

int main(){
  int N, K;
  cin >> N >> K;
  int T[K], X[K], Y[K];
  for(int i = 0; i < K; i++){
    cin >> T[i] >> X[i] >> Y[i];
  }

  UnionFind tree(N * 3);

  int ans = 0;
  for(int i = 0; i < K; i++){
    int t = T[i];
    int x = X[i] - 1, y = Y[i] - 1;

    // 正しくない番号
    if(x < 0 || N <= x || y < 0 || N <= y){
      ans++;
      continue;
    }

    if(t == 1){
      // xとyは同じ種類
      if(tree.same(x, y + N) || tree.same(x, y + 2 * N)){
        ans++;
      }
      else {
        tree.unite(x, y);
        tree.unite(x + N, y + N);
        tree.unite(x + N * 2, y + N * 2);
      }
    }
    else {
      // xはyを食べる
      if(tree.same(x, y) || tree.same(x, y + 2 * N)){
        ans++;
      }
      else {
        tree.unite(x, y + N);
        tree.unite(x + N, y + 2 * N);
        tree.unite(x + 2 * N, y);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
