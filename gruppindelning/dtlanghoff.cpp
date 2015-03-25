#include <iostream>
#include <map>
#include <string>
#include <vector>
 
using namespace std;
 
class UnionFind {
private:
  vector<int> p, rank;
  int nsets;
public:
  UnionFind(int n) {
    nsets = n;
    p.assign(n, 0); rank.assign(n, 0);
    for (int i = 0; i < n; i++)
      p[i] = i;
  }
  int find_set(int i) {
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
  }
  bool same_set(int i, int j) {
    return find_set(i) == find_set(j);
  }
  int union_set(int i, int j) {
    if (!same_set(i, j)) {
      nsets--;
      int x = find_set(i), y = find_set(j);
      if (rank[x] > rank[y])
        p[y] = p[x];
      else {
        p[x] = p[y];
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
  int num_sets() {
    return nsets;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
 
  map<string, int> names;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    names[s] = i;
  }
 
  UnionFind kompis(n);
 
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    string a, b; cin >> a >> b;
    kompis.union_set(names[a], names[b]);
  }
 
  cout << kompis.num_sets() << "\n";
}
