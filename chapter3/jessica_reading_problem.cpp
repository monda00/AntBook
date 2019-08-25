/* Jessica's Reading Problem
 * しゃくとり法
 */

#include <iostream>
#include <set>
#include <map>

using namespace std;

#define MAX_P 1000000

// 入力
int P;
int a[MAX_P];

int main(){
  cin >> P;
  for(int i = 0; i < P; i++){
    cin >> a[i];
  }

  // 書かれている事柄の総数を計算
  set<int> all;
  for(int i = 0; i < P; i++){
    all.insert(a[i]);
  }
  int n = all.size();

  // しゃくとり法により解を求める
  int s = 0, t = 0, num = 0;
  map<int, int> count; // 事柄->出現数の対応
  int res = P;
  for(;;){
    while(t < P && num < n){
      if(count[a[t++]]++ == 0){
        // 新しい事柄が出現
        num++;
      }
    }
    if(num < n) break;
    res = min(res, t - s);
    if(--count[a[s++]] == 0){
      // ある事柄の出現数が0になった
      num--;
    }
  }

  cout << res << endl;

  return 0;
}
