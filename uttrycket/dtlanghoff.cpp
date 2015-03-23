#include <iostream>
#include <limits>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
  string str;
  vector<long long> tal;
  vector<char> op;
 
  getline(cin, str);
 
  long long t = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= '0') {
      t *= 10;
      t += str[i] - '0';
    }
    else {
      tal.push_back(t);
      t = 0;
      op.push_back(str[i]);
    }
  }
  tal.push_back(t);
 
  int n = tal.size();
  vector<vector<long long> > low(n, vector<long long>(n));
  vector<vector<long long> > high(n, vector<long long>(n));
  for (int i = 0; i < n; i++)
    low[0][i] = high[0][i] = tal[i];
 
  
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n-i; j++) {
      long long h = numeric_limits<long long>::min();
      long long l = numeric_limits<long long>::max();
      for (int k = 0; k < i; k++) {
        long long lhigh = high[k][j];
        long long rhigh = high[i-k-1][j+k+1];
        long long llow = low[k][j];
        long long rlow = low[i-k-1][j+k+1];
        char p = op[j+k];
        if (p == '+') {
          h = max(h, lhigh+rhigh);
          l = min(l, llow+rlow);
        }
        else if (p == '-') {
          h = max(h, lhigh-rlow);
          l = min(l, llow-rhigh);
        }
        else if (p == '*') {
          h = max(h, max(max(lhigh*rhigh, lhigh*rlow), max(llow*rhigh, llow*rlow)));
          l = min(l, min(min(lhigh*rhigh, lhigh*rlow), min(llow*rhigh, llow*rlow)));
        }
      }
      high[i][j] = h;
      low[i][j] = l;
    }
  }
 
  cout << high[n-1][0] << "\n";
}
