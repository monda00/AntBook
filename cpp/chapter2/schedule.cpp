/* 貪欲法
 * 選べる仕事の中でもっとも早く終わるものを選択する
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> s;
vector<int> t;
vector<pair<int, int> > itv;

int main(){
  cin >> n;
  s = vector<int>(n);
  t = vector<int>(n);
  itv = vector<pair<int, int> >(n);

  for(int i=0; i < n; i++){
    cin >> s[i];
  }
  for(int i=0; i < n; i++){
    cin >> t[i];
  }

  for(int i=0; i < n; i++){
    itv[i].first = t[i];
    itv[i].second = s[i];
  }
  sort(itv.begin(), itv.end());

  int ans = 0, finish_time = 0;
  for(int i=0; i < n; i++){
    if(finish_time < itv[i].second){
      ans++;
      finish_time = itv[i].first;
    }
  }

  cout << ans << endl;

  return 0;
}
