#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
  vector<int> t(2);
  vector<vector<int> > v(2);
 
  cin >> t[0] >> t[1];
  for (int i = 0; i < 2; i++) {
    while (t[i] != 1) {
      v[i].push_back(t[i]);
      t[i] = (t[i] % 2 == 0) ? (t[i]/2) : (3*t[i]+1);
    }
    v[i].push_back(1);
  }
 
  for (int j = 1; j <= min(v[0].size(), v[1].size()); j++) {
    if (v[0][v[0].size()-j] != v[1][v[1].size()-j]) {
      cout << 2 + (v[0].size() - j) + (v[1].size() - j) << endl;
      return 0;
    }
  }
 
  cout << abs((int) (v[0].size() - v[1].size())) << endl;
  return 0;
}
