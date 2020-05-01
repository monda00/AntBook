/* 適当なwからはじめ、繋がっているwを.に置き換えていくように繰り返す。
 * mainからdfsを呼び出した数が答えになる。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > field;
int n, m;

void dfs(int x, int y){
  field[x][y] = '.';

  for(int dx=-1; dx <= 1; dx++){
    for(int dy=-1; dy <= 1; dy++){
      int next_x = x + dx;
      int next_y = y + dy;

      if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m &&
          field[next_x][next_y] == 'w'){
        dfs(next_x, next_y);
      }
    }
  }
  return;
}

int main(void){
  cin >> n >> m;
  field = vector<vector<char> >(n, vector<char>(m, 0));
  for(int i=0; i < field.size(); i++){
    for(int j=0; j < field[i].size(); j++){
      cin >> field[i][j];
    }
  }

  int lake_num = 0;
  for(int i=0; i < field.size(); i++){
    for(int j=0; j < field[i].size(); j++){
      if(field[i][j] == 'w'){
        dfs(i, j);
        lake_num++;
      }
    }
  }

  cout << lake_num << endl;

  return 0;
}


