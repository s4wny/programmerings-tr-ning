#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N, M, conn;
string name1, name2;
map<string, int> names;
vector<vector<int>> adjacencyList;
vector<bool> seen;

void dfs(int node) {
    seen[node] = true;

    for(int i = 0; i < adjacencyList[node].size(); ++i) {
        if(!seen[adjacencyList[node][i]])
            dfs(adjacencyList[node][i]);
    }
}

int main() {
    // Simulates 'sawny.cpp < input.txt'
    freopen("data/input.txt", "r", stdin);

    cin >> N;
    seen.assign(N, false);
    adjacencyList.assign(N, vector<int>());

    while(N--) {
        cin >> name1;
        names[name1] = N;
    }

    //Build a adjacencyList with the nodes
    cin >> M;
    while(M--) {
        cin >> name1 >> name2;
        adjacencyList[names[name1]].push_back(names[name2]);
        adjacencyList[names[name2]].push_back(names[name1]);
    }


    //Count how many graphs that exists in our adjacencyList
    int counter = 0;
    for(auto x : names) {
        if(!seen[x.second]) {
            dfs(x.second);
            counter++;
        }
    }

    cout << counter << endl;
}
