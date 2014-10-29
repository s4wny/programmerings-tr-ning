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
vector<int> goal = {1,2,3,4,5,6,7,8,0};


std::queue<pair<vi, int>> bfsQ;

map<vi, int> dist;


inline void connect(vi & current, int& hole, int newpos)
{
    
    if(newpos < 9 && newpos >= 0)
    {
        vi new_mat(current);
        new_mat[newpos] = 0;
        new_mat[hole] = current[newpos];
        if(dist[new_mat] == -1)
        {
            bfsQ.push(make_pair(new_mat, newpos));
            dist[new_mat] = dist[current] + 1;
        }
    }
    
}


int main()
{    
    int hole;

    vector<int> cb;
    
    
    //dist to each matrix
    for(int i = 0; i<9; i++)
    {
        cb.push_back(i);
    }
    
    do {
        dist[cb] = -1;
    }while (next_permutation(cb.begin(), cb.end()));
    

    
    goal.assign(9, 0);
    
    //Get the cube
    for(int i = 0; i<9; i++)
    {
        int num; 
        cin >> num;
        if(num == 0)
            hole = i;
        
        cube.push_back(num);
    }
   
    
    bfsQ.emplace(make_pair(cube, hole));
    
    dist[cube] = 0;
    
    
    //BFS
    while(!bfsQ.empty())
	{
        
		vi current = bfsQ.front().first; //curent vertex
        hole = bfsQ.front().second;
		bfsQ.pop();
        
        if(current == goal)
            break;
        
        if(hole % 3 != 2)
            connect(current, hole, hole+1);
        if(hole % 3 != 0)
            connect(current, hole, hole-1);
		connect(current, hole, hole+3);
        connect(current, hole, hole-3);
	}
    
    
    cout << dist[goal];

}

