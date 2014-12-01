#include <iostream>
#include <vector>
#include <string.h>
 
#define VISITED  1
#define UNVISTED 0
 
using namespace std;
 
int N, M, startX = -1, startY, endX, endY;
vector<vector<char>> theMap;
int visitedPlaces[501][501];
 
// Hur en häst i shack kan hoppa, läs kolumn för kolum.
int xMov[8] = {-1, -1, -2, -2,  1, 1,  2, 2};
int yMov[8] = {-2,  2, -1,  1, -2, 2, -1, 1};
 
void dfs(int x, int y) {
    char entity;
    int nX;
    int nY;
 
    if(x == endX && y == endY) {
        return;
    }
 
    for(int i = 0; i < 8; i++) {
        nX = x + xMov[i];
        nY = y + yMov[i];
 
        if(nX > -1 && nX < M && nY > -1 && nY < N) {
            entity = theMap[nY][nX];
 
            if(entity != '#' && visitedPlaces[nY][nX] == UNVISTED) {
                visitedPlaces[nY][nX] = VISITED;
                dfs(nX, nY);
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
    char entity;
    cin >> N >> M;
    theMap.assign(N, vector<char>(M));
    memset(visitedPlaces, UNVISTED, sizeof(visitedPlaces[0][0])*501*501);
 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> entity;
            theMap[i][j] = entity;
 
            if(entity == 'H') {
                if(startX == -1) {
                    startX = j;
                    startY = i;
                }
                else {
                    endX = j;
                    endY = i;
                }
            }
        }
    }
 
    dfs(startX, startY);
 
    cout << ((visitedPlaces[endY][endX] == VISITED) ? "JA" : "NEJ");
}