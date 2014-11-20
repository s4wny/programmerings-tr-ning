#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    
    int N, gunnar, x, c = 0;
    priority_queue<int> xs;  // Kommer alltid vara sorterad.
    cin >> N >> gunnar;
    
    // Läs in alla siffror i sorterad ordning
    while(!(cin >> x).eof())
        xs.push(x); // Insättning av element tar i snitt O(log n)
    
    // Ta girigt bort en från personen med flest röster och ge till karl gunnar 
    while(gunnar <= xs.top()) {
        int top = xs.top(); xs.pop(); // log(N)
        xs.push(top-1);
        c++;
        gunnar++;
    }
 
    cout << c;
}