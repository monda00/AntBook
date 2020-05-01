#include <iostream>
#include <vector>

using namespace std;

bool dfs(int i, int sum, int n, int k, vector<int> v){
  if(i == n) return sum == k;

  if(dfs(i + 1, sum, n, k, v)) return true;

  if(dfs(i + 1, sum + v[i], n, k, v)) return true;

  return false;
}

int main(){
  int n, k;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i < v.size(); i++) cin >> v[i];
  cin >> k;

  if(dfs(0, 0, n, k, v)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
