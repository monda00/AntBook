/* Fence Repair
 * 順位キュー
 */

#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main(){
  int N;
  cin >> N;
  int L[N];
  for(int i = 0; i < N; i++){
    cin >> L[i];
  }

  ll ans = 0;

  // 順位キューを用意（小さい数から出てくるようにする
  priority_queue<int, vector<int>, greater<int> > que;
  for(int i = 0; i < N; i++){
    que.push(L[i]);
  }

  // 枝が１本になるまで適用
  while(que.size() > 1){
    // 1番短い板、次に短い板を取り出す
    int l1, l2;
    l1 = que.top();
    que.pop();
    l2 = que.top();
    que.pop();

    // それらを結合
    ans += l1 + l2;
    que.push(l1 + l2);
  }

  cout << ans << endl;

  return 0;
}
