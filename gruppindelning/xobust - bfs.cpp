#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <map>

bool rev (int i,int j) { return (i>j); }

#define vi std::vector<int>

using namespace std;


vector<bool> visited;

std::vector<int> adjlist[110];

std::queue<int> bfsQ;



std::map<string, int> table;


int main()
{
	
	std::ios_base::sync_with_stdio(false);

	int n,m;

	cin >> n;

	visited.assign(n,false);

	string s;

	for(int i = 0; i<n; i++)
	{
		cin >> s;
		table[s] = i;
	}

	cin >> m;

	string ss;
	for(int i = 0; i<m; i++)
	{
		cin >> s;
		cin >> ss;

		adjlist[table[s]].push_back(table[ss]);
		adjlist[table[ss]].push_back(table[s]);
	}



	int connected = 0;
	
	//bfs
	for(int i = 0;i<n;i++)
	{
		if(!visited[i])
		{
			visited[i] = true;

			bfsQ.emplace(i);

			while(!bfsQ.empty())
			{
				int current = bfsQ.front(); //curent vertex
				bfsQ.pop();

				for(auto it = adjlist[current].begin(); it != adjlist[current].end();it++)
				{
					
					if(!visited[*it])
					{
						bfsQ.push(*it);
						visited[*it] = true;
					}
				}			
			}

			connected++;
		}
	}




	cout<<connected;
}
