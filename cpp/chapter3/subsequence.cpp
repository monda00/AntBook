/* Subsequence
 * しゃくとり法
 */

#include <iostream>

using namespace std;

#define MAX_N  100000

// 入力
int n, S;
int a[MAX_N];

int sum[MAX_N + 1];

int main() {
  cin >> n >> S;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int res = n + 1;
  int s = 0, t = 0, sum = 0;

  for (;;) {
    cout << "s = " << s << "t = " << t << endl;
    while (t < n && sum < S) {
      sum += a[t++];
    }
    if(sum < S) break;
    res = min(res, t - s);
    sum -= a[s++];
  }

  if (res > n) {
    // 解が存在しない
    res = 0;
  }

  cout << res << endl;

  return 0;
}

