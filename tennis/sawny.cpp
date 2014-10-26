#include <iostream>
#include <vector>
#include <queue>

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

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    wbstdin;

    //Read all variables and build an Adjacency List
    int N, K, M, w, l, INF = -1; // INF = -1 cuz we should return -1 if not possible to reach 1 rank
    cin >> N >> K >> M;
    ++N;
    vvi adjacencyList(N, vi());
    while((!(cin >> w >> l).eof()))
        adjacencyList[w].push_back(l);

    //Prepare for BFS
    queue<int> theQueue;
    theQueue.push(K);
    vi dist(N, INF); // We'll  build a table with the distance from vertex K to everyother vertex.
    dist[K] = 0;

    //BFS
    while(!theQueue.empty()) {
        int parentVertex = theQueue.front();
        theQueue.pop();

        for(int vertex : adjacencyList[parentVertex]) {
            if(dist[vertex] == INF) { //Unvisited
                theQueue.push(vertex);
                dist[vertex]   = dist[parentVertex] + 1;
            }
        }
    }

    cout << dist[1] << endl;
}
