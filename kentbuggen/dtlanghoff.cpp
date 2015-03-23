#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
 
  for (int i = 0; i < n; i++)
    cin >> s[i];
 
  sort(s.begin(), s.end());
 
  int m = 0;
  string a = "";
  string b = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == a && s[i] != b)
      m++;
    b = a;
    a = s[i];
  }
 
  cout << m << endl;
  return 0;
}
 
