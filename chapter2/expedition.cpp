/* Expedition
 * プライオリティキュー
 * ガソリンスタンドiを通過した時に、プライオリティキューにB_iを追加する
 * 燃料タンクが空になった時
 *  - プライオリティキューが空であれば、移動は達成できない
 *  - プライオリティキューからもっとも大きい数字を取り出し、そこでガソリンを補給した時にする
 */

#include <iostream>
#include <queue>

using namespace std;

int main(){
  int L, P, N;
  cin >> N >> L >> P;
  int A[N + 1], B[N + 1];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  for(int i = 0; i < N; i++){
    cin >> B[i];
  }

  // ゴールをガソリンスタンドを追加
  A[N] = L;
  B[N] = 0;
  N++;

  // ガソリンスタンドを管理する順位キュー
  priority_queue<int> que;

  // ans:補給回数、pos:今いる場所、tank:タンクのガソリンの量
  int ans = 0, pos = 0, tank = P;

  for(int i = 0; i < N; i++){
    // 次に進む距離
    int d = A[i] - pos;

    // 十分な量になるまでガソリンを補給
    while(tank - d < 0){
      if(que.empty()){
        cout << -1 << endl;
        return 0;
      }
      tank += que.top();
      que.pop();
      ans++;
    }
    tank -= d;
    pos = A[i];
    que.push(B[i]);
  }

  cout << ans << endl;

  return 0;
}
