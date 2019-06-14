/* 貪欲法
 * Sの先頭と末尾の小さい方をTの末尾に付け加える
 * ただし、辞書順比較なので、SとSを反転させた文字列を辞書順比較する
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<char> st(n);
  for(int i=0; i < n; i++){
    cin >> st[i];
  }

  int from_front = 0, from_back = n - 1;

  while(from_front <= from_back){
    bool left = false;
    for(int i = 0; from_front + i <= from_back; i++){
      if(st[from_front + i] < st[from_back - i]){
        left = true;
        break;
      }
      else if(st[from_front + i] > st[from_back - i]){
        left = false;
        break;
      }
    }

    if(left) cout << st[from_front++];
    else cout << st[from_back--];
  }
  cout << endl;

  return 0;
}
