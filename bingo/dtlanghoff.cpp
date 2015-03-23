#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
 
  vector<map<int, int> > w(2*n+2);
  vector<int> u(k);
 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int b;
      cin >> b;
      w[i][b]++;
      w[n+j][b]++;
      if (i == j)
        w[2*n][b]++;
      if (i+j == n-1)
        w[2*n+1][b]++;
    }
  }
 
  for (int i = 0; i < k; i++)
    cin >> u[i];
 
  int a = 0;
  int b = k;
  map<int, int> t;
 
  while (b - a > 1) {
    int g = (a+b) / 2;
    for (int i = 0; i < g; i++)
      t[u[i]]++;
 
    bool s = false;
    for (int i = 0; i < w.size(); i++) {
      bool r = false;
      for (map<int, int>::iterator j = w[i].begin(); j != w[i].end(); j++) {
        if ((j->second) > t[j->first]) {
          r = true;
          break;
        }
      }
      if (!r) {
        s = true;
        break;
      }
    }
 
    if (s) {
      b = g;
    }
    else {
      a = g;
    }
    t.clear();
  }
 
  cout << b << endl;
  return 0;
}
