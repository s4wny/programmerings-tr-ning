#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <map>

bool rev (int i,int j) { return (i>j); }

//Vi is short for vector<int>
#define vi std::vector<int>

using namespace std;



//data structures

vi adjlist[40000];

vi dist;

std::queue<int> bfsQ;

std::map<string, int> namel;


//last unused id
int nextint;


//returns the id of the autur
int id(string s)
{
    if(namel.find(s) == namel.end())
        namel[s] = nextint++;
    
    return namel[s];
    
}


int main()
{
    nextint = 0; // set the first id in the lookup table

    std::ios_base::sync_with_stdio(false);
    
    int n,m;
    
    cin >> n >> m;
    
    dist.assign(n+1, -1);

    //Get all articles
    for(int i = 0; i<m; i++)
    {
        int num; //number of colaborators
        cin >> num;
        
        vi temp; // temporary list to put all the article authors in
        for (int j = 0; j<num; j++) {
            string s;
            int p;
            
            cin >> s;
            
            p = id(s);
            temp.push_back(p);
        }
        
        //Connect all pairs of authurs
        for(int a : temp)
            for(int b: temp)
                if(a != b)
                    adjlist[a].push_back(b);
    }
    
    
    //prepare dfs
    int ERDOS = id("ERDOS");
    dist[ERDOS] = 0;
    
    bfsQ.emplace(ERDOS);
    
    //DFS
            while(!bfsQ.empty())
			{
                
				int current = bfsQ.front(); //curent vertex
				bfsQ.pop();
                
				for(auto it = adjlist[current].begin(); it != adjlist[current].end();it++)
				{
					
					if(dist[*it] == -1)
					{
                        dist[*it] = dist[current] +1;
						bfsQ.push(*it);
					}
				}
			}

    //List results
    
    for (auto it=namel.begin(); it!=namel.end(); ++it){
        std::cout << it->first << " " << dist[it->second] << '\n';
    }
    
}

