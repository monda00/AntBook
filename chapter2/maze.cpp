/* 幅優先探索で最短手数を求める
 * キューを使って実装
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;

typedef pair<int, int> P;

vector<vector<char> > maze;
int n, m;
int start_x, start_y;
int goal_x, goal_y;
vector<vector<int> > d;

// 移動方向のベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(){
  queue<P> que;

  for(int i=0; i < n; i++){
    for(int j=0; j < m; j++){
      d[i][j] = INF;
    }
  }

  que.push(P(start_x, start_y));
  d[start_x][start_y] = 0;

  while(que.size()){
    // 先頭を取り出す
    P p = que.front();
    que.pop();

    // ゴールなら終わり
    if(p.first == goal_x && p.second == goal_y)
      break;

    // ４方向をループ
    for(int i=0; i < 4; i++){
      int next_x = p.first + dx[i];
      int next_y = p.second + dy[i];

      // 移動可能か
      if(0 <= next_x && next_x < n && 0 <= next_x && next_y < m &&
          maze[next_x][next_y] != '#' && d[next_x][next_y] == INF){
        que.push(P(next_x, next_y));
        d[next_x][next_y] = d[p.first][p.second] + 1;
      }
    }
  }

  return d[goal_x][goal_y];
}

int main(){
  cin >> n >> m;
  maze = vector<vector<char> >(n, vector<char>(m, 0));
  d = vector<vector<int> >(n, vector<int>(m, 0));
  for(int i=0; i < maze.size(); i++){
    for(int j=0; j < maze[i].size(); j++){
      cin >> maze[i][j];
      if(maze[i][j] == 'S'){
        start_x = i;
        start_y = j;
      }
      else if(maze[i][j] == 'G'){
        goal_x = i;
        goal_y = j;
      }
    }
  }

  int ans = bfs();
  cout << ans << endl;

  return 0;
}
