#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    wbstdin;

    //Read all variables and build an Adjacency List
    int N, M, P, counter = 0, INF = -1;
    string name;
    map<string, int> names;
    map<int, string> ids;

    cin >> N >> M;
    vector<vector<int>> adjacencyList(N, vector<int>());
    while(M--) {
       vector<string> tmpnames;

        // Read all names for the publication
        cin >> P;
        while(P--) {
            cin >> name;
            tmpnames.push_back(name);

            // Give every name an uniqe ID
            if(names.find(name) == names.end()) {
                ids[counter] = name;
                names[name]  = counter++;
            }
        }

        for(string name1 : tmpnames)
            for(string name2 : tmpnames)
                adjacencyList[names[name1]].push_back(names[name2]);
    }

    //Prepare for BFS
    queue<int> theQueue;
    theQueue.push(names["ERDOS"]);
    vector<int> dist(N, INF); // We'll  build a table with the distance from vertex ERDOS to everyother vertex.
    dist[names["ERDOS"]] = 0;

    //BFS
    while(!theQueue.empty()) {
        int parentVertex = theQueue.front();
        theQueue.pop();

        for(int vertex : adjacencyList[parentVertex]) {
            if(dist[vertex] == INF) { //Unvisited
                theQueue.push(vertex);
                dist[vertex] = dist[parentVertex] + 1;
            }
        }
    }

    // Build the result
    vector<pair<string, int>> result;
    for(int i = 0; i < dist.size(); ++i)
        result.push_back(make_pair(ids[i], dist[i]));

    sort(result.begin(), result.end());

    for(auto x : result) {
        cout << x.first << " " << x.second << endl;
    }
}
