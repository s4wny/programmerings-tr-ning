#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
  int N, n, S, s;
  string k;
  cin >> k;
 
  n = 0;
  s = 1;
  for (int i = 0; i < k.length(); i++) {
    if (k[i] == 'N') {
      N = min(n+1, s+1);
      S = min(n+1, s);
    }
    else if (k[i] == 'S') {
      N = min(n, s+1);
      S = min(n+1, s+1);
    }
    else {
      N = min(n+1, s+2);
      S = min(n+2, s+1);
    }
    n = N;
    s = S;
  }
 
  cout << min(N, S+1) << endl;
  return 0;
}
