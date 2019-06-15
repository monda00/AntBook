#include <iostream>
#include <vector>

using namespace std;


int main(){
  int n, r;
  cin >> n;
  cin >> r;
  vector<int> x(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }

  sort(x.begin(), x.end());

  int i = 0, ans = 0;
  while(i < n){
    int s = x[i++];
    while(i < n && x[i] <= s + r) i++;

    int p = x[i - 1];
    while(i < n && x[i] <= p + r) i++;

    ans++;
  }

  cout << ans << endl;

  return 0;
}
