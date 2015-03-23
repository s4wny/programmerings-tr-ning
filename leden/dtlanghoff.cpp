#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int main() {
  int n, a, b;
  cin >> n >> a;
 
  int t = 0;
 
  for (int i = 0; i < n; i++) {
    cin >> b;
    t += 60 + 2*abs(-5 - (b-a));
    a = b;
  }
 
  cout << t << endl;
  return 0;
}
