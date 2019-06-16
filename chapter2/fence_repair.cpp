/* 貪欲法
 *
 */

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  for(int i = 0; i < n; i++){
    cin >> l[i];
  }

  ll ans = 0;

  // 板が1になるまで
  while(n > 1){
    // 一番短いmii1、次に短いmii2を求める
    int mii1 = 0, mii2 = 1;
    if(l[mii1] > l[mii2]) swap(mii1, mii2);

    for(int i = 2; i < n; i++){
      if(l[i] < l[mii1]){
        mii2 = mii1;
        mii1 = i;
      }
      else if(l[i] < l[mii2]){
        mii2 = i;
      }
    }

    // まとめて、追加
    int t = l[mii1] + l[mii2];
    ans += t;

    if(mii1 == n - 1) swap(mii1, mii2);
    // まとめたのを最短の板、最後の板を2番目に最短の板のところに上書き
    l[mii1] = t;
    l[mii2] = l[n - 1];
    n--;
  }

  cout << ans << endl;

  return 0;
}
