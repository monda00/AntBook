#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> used;
vector<int> perm;
vector<int> perm2;

void permutation1(int pos, int n){
  if(pos == n){
    return;
  }

  for(int i=0; i < n; i++){
    if(!used[i]){
      perm.push_back(i);
      used[i] = true;
      permutation1(pos + 1, n);
      used[i] = false;
    }
  }
  return;
}

void permutation2(int n){
  for(int i=0; i < n; i++){
    perm2.push_back(i);
  }
  do{
  }while(next_permutation(perm2.begin(), perm2.end()));
  return;
}

int main(){
  for(int i=0; i < 10; i++){
    used.push_back(false);
  }
  permutation2(10);
}
