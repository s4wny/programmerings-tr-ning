#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

//Useful debug functions
#define DEBUG true
#ifdef DEBUG
    #include <cstdio>
    #include "prettyprint.hpp"

    #define nl cout << endl;
    #define debug(x) cout << #x << " = " << x << endl;
    #define wbstdin freopen("input.txt", "r", stdin);
#else
    #define EMPTYSTMT do { } while(0)
    #define nl EMPTYSTMT
    #define debug(x) EMPTYSTMT
    #define wbstdin EMPTYSTMT
#endif // DEBUG


// --------------------------------
// Actual program starts here
//

#define all(x) x.begin(), x.end()

using namespace std;

typedef vector<int> vi;

vi b;
vi finalB = {1,2,3,4,5,6,7,8,0};

// Can we move a piece up/rt/dn/lt?
bool canUp(vi &b) { return !(b[6] == 0 || b[7] == 0 || b[8] == 0); }
bool canRt(vi &b) { return !(b[0] == 0 || b[3] == 0 || b[6] == 0); }
bool canDn(vi &b) { return !(b[0] == 0 || b[1] == 0 || b[2] == 0); }
bool canLt(vi &b) { return !(b[2] == 0 || b[5] == 0 || b[8] == 0); }

// Move a piece up/rt/dn/lt
vi up(vi b) { iter_swap(find(all(b), 0), find(all(b), 0)+3); return b; }
vi rt(vi b) { iter_swap(find(all(b), 0), find(all(b), 0)-1); return b; }
vi dn(vi b) { iter_swap(find(all(b), 0), find(all(b), 0)-3); return b; }
vi lt(vi b) { iter_swap(find(all(b), 0), find(all(b), 0)+1); return b; }


int main() {
    ios_base::sync_with_stdio(false);
    wbstdin;

    int x, INF = -1;
    for(int i = 8; i >= 0; --i) {
        cin >> x;
        b.push_back(x);
    }


    //Special case
    if(b == finalB) {
        cout << 0 << endl;
        return 0;
    }

    // Initial adjacency list
    map<vi, vector<vi>> adjacencyList;
    vector<vi> children;
    if(canUp(b)) children.push_back(up(b));
    if(canRt(b)) children.push_back(rt(b));
    if(canDn(b)) children.push_back(dn(b));
    if(canLt(b)) children.push_back(lt(b));
    adjacencyList[b] = children;

    queue<vi> q;
    q.push(b);
    map<vi, int> dist;
    dist[b] = 0;

    // Breath Depth First Search
    while(!q.empty()) {
        vi parentB = q.front();
        q.pop();

        for(vi b : adjacencyList[parentB]) {
            if(dist.find(b) == dist.end()) {

                //Speed up ~0.04 seconds on kattis
                if(b == finalB) {
                    cout << dist[parentB] + 1;
                    return 0;
                }

                // We got an implict graph, so we need to build it on the fly
                vector<vi> children;
                if(canUp(b)) children.push_back(up(b));
                if(canRt(b)) children.push_back(rt(b));
                if(canDn(b)) children.push_back(dn(b));
                if(canLt(b)) children.push_back(lt(b));
                adjacencyList[b] = children;
                q.push(b);

                // Distance table
                dist[b] = dist[parentB] + 1;

            }
        }
    }

    cout << dist[finalB] << endl;
}
