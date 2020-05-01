/* Roadblocks
 * グラフアルゴリズム
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 5000
#define INF 9999999

struct edge{ int from, to, cost; };
typedef pair<int, int> P;

int N, R;

vector<edge> G[MAX_N];

int dist[MAX_N];
int dist2[MAX_N];

int main(){
  cin >> N >> R;
  for(int i = 0; i < R; i++){
    edge e;
    cin >> e.from >> e.to >> e.cost;
    G[e.from].push_back(e);
    G[e.to].push_back(e);
  }

  priority_queue<P, vector<P>, greater<P> > que;
  fill(dist, dist + N, INF);
  fill(dist2, dist2 + N, INF);
  dist[0] = 0;
  que.push(P(0, 0));

  while(!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second, d = p.first;
    if(dist2[v] < d) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge &e = G[v][i];
      int d2 = d + e.cost;
      if(dist[e.to] > d2){
        swap(dist[e.to], d2);
        que.push(P(dist[e.to], e.to));
      }
      if(dist2[e.to] > d2 && dist[e.to] < d2){
        dist2[e.to] = d2;
        que.push(P(dist2[e.to], e.to));
      }
    }
  }

  cout << dist2[N - 1] << endl;

  return 0;
}

