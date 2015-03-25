#include <iostream>
#include <vector>
 
using namespace std;
 
bool winning(vector<vector<int> >& dp, int a, int b) {
  int x = max(a, b), y = min(a, b);
  if (dp[x][y] != -1)
    return dp[x][y];
  else {
    int w = 0;
    for (int i = 1; i <= x/2; i++) {
      if (!(winning(dp, x-i, y) || winning(dp, i, y))) {
        w = 1;
        break;
      }
    }
    if (w == 0) {
      for (int i = 1; i <= y/2; i++) {
        if (!(winning(dp, x, y-i) || winning(dp, x, i))) {
          w = 1;
          break;
        }
      }
    }
    dp[x][y] = w;
    return w;
  }
}
 
int main() {
  ios::sync_with_stdio(false);
 
  int n, m; cin >> n >> m;
  vector<vector<int> > dp(max(n, m)+1, vector<int>(min(n, m)+1, -1));
  dp[1][1] = 0;
  cout << ((winning(dp, n, m) == 1) ? "A\n" : "B\n");
}
