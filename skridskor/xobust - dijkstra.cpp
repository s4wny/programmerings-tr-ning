
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <string>

using namespace std;

/*
Väldigt lik lösningen för orientering
*/

typedef long long ll;

struct ent
{
    
    ent(int a, string b)
    {
        t = a;
        type = b;
    }
    
    int t;
    string type;
    

    
};

struct Comp{
    bool operator()(const ent& a, const ent& b){
        return a.t>b.t;
    }
};

priority_queue<ent, vector<ent>, Comp> pq;

// tävlingsprogrammeirng.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


char arr[802][802];
int dist[802][802][4];
bool scanned[802][802][4];

int N, M;
int R, C;

struct bfs_data
{
    bfs_data(int a, int b, char c, int p)
    {
        x = a;
        y = b;
        dir = c;
        prio = p;
    }
    
    int prio;
    int x;
    int y;
    char dir;
};

bool operator<(const bfs_data & a, const bfs_data & b)
{
    return (a.prio > b.prio);
}


std::priority_queue<bfs_data> bfsQ;


int main() {
    
    
    std::ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    
    int low = 999999;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char t = ' ';
            cin >> t;
            arr[j][i] = t;
            dist[j][i][0] = 99999;
            dist[j][i][1] = 99999;
            dist[j][i][2] = 99999;
            dist[j][i][3] = 99999;
            scanned[j][i][0] = false;
            scanned[j][i][1] = false;
            scanned[j][i][2] = false;
            scanned[j][i][3] = false;
        }
    }
    
    dist[1][1][2] = 0;
    
    bfsQ.emplace(bfs_data(1, 1, '>', 0));
    
    while (!bfsQ.empty())
    {
        
        int x = bfsQ.top().x;
        int y = bfsQ.top().y;        //curent vertex
        char dir = bfsQ.top().dir;
        bfsQ.pop();
        
        
        if (!(x > M || x<1 || y>N || y < 1) && arr[x][y] != '#')
        {
            
            int n_x = x, n_y = y;
            
            int t=-1; //direction indicator
            if (dir == '^')
            {
                n_y--;
                t = 0;
            }
            else if (dir == 'v')
            {
                n_y++;
                t = 1;
            }
            else if (dir == '>')
            {
                n_x++;
                t = 2;
            }
            else if (dir == '<')
            {
                n_x--;
                t = 3;
            }
            
            
            if (!scanned[x][y][t])
            {
                
                if (x == M)
                {
                    if(dist[x][y][t] < low)
                        low = dist[x][y][t];
                    
                    break;
                }
                
                scanned[x][y][t] = true;
                
                
                
                if (arr[n_x][n_y] != '#')
                {
                    if (!scanned[n_x][n_y][t])
                    {
                        if (dist[x][y][t] < dist[n_x][n_y][t])
                        {
                            dist[n_x][n_y][t] = dist[x][y][t];
                            bfsQ.push(bfs_data(n_x, n_y, dir, dist[x][y][t]));
                        }
                        
                    }
                }
                else
                {
                    
                    n_y = y;
                    n_x = x;
                    
                    int n_t = -1;
                    
                    char ndir = '>';
                    
                    if (dir == '^')
                    {
                        n_x --;
                        n_t = 3;
                        ndir= '<';
                    }
                    else if (dir == 'v')
                    {
                        n_x--;
                        n_t = 3;
                        ndir= '<';
                    }
                    else if (dir == '>')
                    {
                        n_y--;
                        n_t = 0;
                        ndir= '^';
                    }
                    else if (dir == '<')
                    {
                        n_y--;
                        n_t = 0;
                        ndir= '^';
                    }
                    
                    
                    if (!scanned[n_x][n_y][n_t])
                    {
                        if (dist[x][y][t] < dist[n_x][n_y][n_t] + 1)
                        {
                            dist[n_x][n_y][n_t] = dist[x][y][t]+1;
                            bfsQ.push(bfs_data(n_x, n_y, ndir, dist[x][y][t] + 1));
                        }
                        
                    }
                    
                    n_y = y;
                    n_x = x;
                    
                    n_t = -1;
                    
                    if (dir == '^')
                    {
                        n_x ++;
                        n_t = 2;
                        ndir= '>';
                    }
                    else if (dir == 'v')
                    {
                        n_x++;
                        n_t = 2;
                        ndir= '>';
                    }
                    else if (dir == '>')
                    {
                        n_y++;
                        n_t = 1;
                        ndir= 'v';
                    }
                    else if (dir == '<')
                    {
                        n_y++;
                        n_t = 1;
                        ndir= 'v';
                    }
                    
                    
                    if (!scanned[n_x][n_y][n_t])
                    {
                        if (dist[x][y][t] < dist[n_x][n_y][n_t] + 1)
                        {
                            dist[n_x][n_y][n_t] = dist[x][y][t]+1;
                            bfsQ.push(bfs_data(n_x, n_y, ndir, dist[x][y][t] + 1));
                        }
                        
                    }
                    
                }
                
            }
        }
        
        
    }
    
    
    cout << low;
    
    return 0;
}
