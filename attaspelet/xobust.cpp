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
vector<int> cube;
vector<int> goal;


std::queue<pair<vi, int>> bfsQ;

map<vi, int> dist;


inline void connect(vi & current, int& hole, int newpos)
{
    
    if(newpos < 9 && newpos >= 0)
    {
        vi new_mat(current);
        new_mat[newpos] = 0;
        new_mat[hole] = current[newpos];
        if(dist.find(new_mat) == dist.end())
        {
            bfsQ.push(make_pair(new_mat, newpos));
            dist[new_mat] = dist[current] + 1;
        }
    }
    
}


int main()
{
    

    std::ios_base::sync_with_stdio(false);
    
    int hole;

    vector<int> cb;
    
    
    goal.assign(9, 0);
    
    //Get the cube
    for(int i = 0; i<9; i++)
    {
        goal[i] = 1+i;
        int num; //number of colaborators
        cin >> num;
        
        if(num == 0)
            hole = i;
        
        cube.push_back(num);
        
    }
   
    goal[8] = 0;

    
    bfsQ.emplace(make_pair(cube, hole));
    
    dist[cube] = 0;
    
    
    //BFS
            while(!bfsQ.empty())
        	{
                
				vi current = bfsQ.front().first; //curent vertex
                hole = bfsQ.front().second;
				bfsQ.pop();
                
                if(hole % 3 != 2)
                    connect(current, hole, hole+1);
                if(hole % 3 != 0)
                    connect(current, hole, hole-1);
				connect(current, hole, hole+3);
                connect(current, hole, hole-3);
			}
    
    
    cout << dist[goal];

}

