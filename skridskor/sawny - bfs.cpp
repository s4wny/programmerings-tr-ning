#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <tuple>
#include <map>
 
 
#define DIR_U 0
#define DIR_R 1
#define DIR_D 2
#define DIR_L 3
 
using namespace std;
 
int R, C;
vector<vector<char>> theMap;
 
int main() {
    ios_base::sync_with_stdio(false);
 
    char entity;
    cin >> R >> C;
    theMap.assign(R, vector<char>(C));
 
    for(int y = 0; y < R; y++) {
        for(int x = 0; x < C; x++) {
            cin >> entity;
            theMap[y][x] = entity;
        }
    }
 
    map<pair<int, int>, long long int> dist;
    dist[make_pair(0, 0)] = 0;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, DIR_R)); //(y, x, dir)
    

    // DFS börjar här
    while(!q.empty()) {
        tuple<int, int, int> u = q.front();
        q.pop();
        int oldY = get<0>(u);
        int oldX = get<1>(u);
        int dir  = get<2>(u);
        
        // Din nya riktning kommer alltid att vara +90 och -90 grader från den du har nu
        int newDir1 = ((dir + 1) % 4);
        int newDir2 = ((dir == 0) ? 3 : dir - 1);
 
        int newX = -1, newY = -1;
        
        // Gå åt de håll hon åker, gå tills du stöter på ett hinder (#). Det blir din nya position
        switch(dir) {
        case DIR_R:
            for(int x = oldX; x <= C; x++) {
                if(theMap[oldY][x] == '#') {
                    newX = x-1;
                    newY = oldY;
                    break;
                }
                else if(x == C-1) {
                    
                    // Klar, skriv ut svaret! (man kommer alltid åka ut på höger sida)
                    cout << dist[make_pair(oldY, oldX)] << endl;
                    return 0;
                }
            }
        break;
        case DIR_D:
            for(int y = oldY; y < R; y++) {
                if(theMap[y][oldX] == '#') {
                    newX = oldX;
                    newY = y-1;
                    break;
                }
            }
        break;
        case DIR_L:
            for(int x = oldX; x >= 0; x--) {
                if(theMap[oldY][x] == '#') {
                    newX = x+1;
                    newY = oldY;
                    break;
                }
            }
        break;
        case DIR_U:
            for(int y = oldY; y >= 0; y--) {
                if(theMap[y][oldX] == '#') {
                    newX = oldX;
                    newY = y+1;
                    break;
                }
            }
        break;
        }
 
        if(newX == -1 || newY == -1) {
            continue;
        }
 
        //newX == 0 && newY == 0 är ett edge case
        if(dist.find(make_pair(newY, newX)) == dist.end() || newX == 0 && newY == 0) {
            dist[make_pair(newY, newX)] = dist[make_pair(oldY, oldX)] + 1;
            q.push(make_tuple(newY, newX, newDir1));
            q.push(make_tuple(newY, newX, newDir2));
        }
    }
}