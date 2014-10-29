#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <utility>


// --------------------------------
// Actual program starts here
//

#define all(x) x.begin(), x.end()

using namespace std;

typedef vector<int> vi;

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
    vi b, finalB = {1,2,3,4,5,6,7,8,0};
    int x, parentDist = -1;

    while(!(cin >> x).eof())
        b.push_back(x);

    queue<pair<int, vi>> q;
    pair<int, vi> vertex;
    vertex = make_pair(0, b);
    map<vi, int> dist;

    do {
        if(dist.find(b) == dist.end()) {
            dist[b] = parentDist + 1;

            if(b == finalB) {
                cout << dist[b];
                return 0;
            }

            if(canUp(b)) q.push(make_pair(dist[b], up(b)));
            if(canRt(b)) q.push(make_pair(dist[b], rt(b)));
            if(canDn(b)) q.push(make_pair(dist[b], dn(b)));
            if(canLt(b)) q.push(make_pair(dist[b], lt(b)));
        }

        vertex = q.front();
        b  = vertex.second;
        parentDist = vertex.first;
        q.pop();
    } while(true);
}
