#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef vector<vector<int>> vvi;
 
int recur(int x, int y, int k, vvi apples);
int N, K;
 
int main() {
    cin >> N >> K;
    vector<vector<int>> apples(2, vector<int>(N));
 
    for(int i = 0; i < N; ++i) cin >> apples[0][i];
    for(int i = 0; i < N; ++i) cin >> apples[1][i];
 
    cout << recur(0, 1, K, apples) << endl;
}
 
int recur(int x, int y, int k, vvi apples) {
    //Out of bounds
    if(x < 0 || x >= N || y < 0 || y > 1)
        return -1;
 
    --k;
    int applesTaken = apples[y][x];
    apples[y][x] = 0;
 
    if(k == 0)
        return applesTaken;
 
    int best;
    best = recur(x,   y-1, k, apples);
    best = max(best, recur(x+1, y,   k, apples));
    best = max(best, recur(x,   y+1, k, apples));
 
    return applesTaken + best;
}