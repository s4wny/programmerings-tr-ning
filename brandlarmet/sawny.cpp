#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, bool> pib;
typedef pair<int, pib> pipib;

int INF = 99999999;
int N, S, Y, M, P, Q, T;
vector<vector<pipib>> al;

/**
 * Dijkstras algorithm för SSSP, O(E+V log V)
 * Bra tutorial finns på YT: https://www.youtube.com/watch?v=8Ls1RqHCOPw
 *
 * Globala variabler: N, AL
 */
vector<int> SSSP(int start, bool hasKey) {
    vector<int> dist(N, INF);
    dist[start] = 0;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        pair<int, int> front = pq.top(); pq.pop();
        int d = front.first;
        int u = front.second;

        if(d > dist[u]) continue;
        for(int j = 0; j < al[u].size(); j++) {
            pipib v = al[u][j];

            //Låst dörr, går ej att gå igenom (Notera att denna rad är enda ändringen i algoritmen, resten är standard implementation av dijkstras)
            if(v.second.second && !hasKey) continue;

            if(dist[u] + v.second.first < dist[v.first]) {
                dist[v.first] = dist[u] + v.second.first;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    wbstdin;

    char outOrIn, lockedOrNot;
    vector<bool> outside;
    pair<int, bool> weightAndState;

    cin >> N >> S >> Y; //S = start, Y = key
    for(int i = N; i > 0; i--) {
        cin >> outOrIn;
        outside.push_back( outOrIn == 'u' );
    }


    // Bygg en AdjacencyList
    al.assign(N, vector<pipib>());
    cin >> M;
    while(M--) {
        cin >> P >> Q >> T >> lockedOrNot;
        weightAndState = make_pair(T, (lockedOrNot == 'l') );

        al[P].push_back(make_pair(Q, weightAndState));
        al[Q].push_back(make_pair(P, weightAndState));
    }


    // Kör SSSP på AL med låsta dörrar
    vector<int> dist;
    dist = SSSP(S, false);


    // Kortaste vägen
    int shortest = INF;
    for(int i = 0; i < outside.size(); i++) {
        if(outside[i])
            shortest = min(shortest, dist[i]);
    }

    
    int keyDist = dist[Y];

    // Kör Dijkstras med alla dörrar UPPLÅSTA
    dist = SSSP(Y, true);
    for(int i = 0; i < outside.size(); i++)
        if(outside[i])
            shortest = min(shortest, dist[i] + keyDist); //Notera att shortest vid loop 1 = kortaste vägen utan nyckel


    cout << shortest;
}