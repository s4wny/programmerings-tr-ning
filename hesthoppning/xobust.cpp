
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <string>

using namespace std;

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


char grid[500][500];

int N, M;

bool rec(int x, int y, char sym)
{
    
    if(!(y < N))
        return false;
    if(!(x < M))
        return false;
    
    if(x < 0 || y < 0)
        return false;
    
    if(grid[y][x] == '#')
        return false;
    
    if(grid[y][x] == sym)
        return false;
    
    if(grid[y][x] != '.')
        return true;
    else
        grid[y][x] = sym;
    
    
    if(rec(x+2, y+1,sym))
        return true;
    else if(rec(x+2,y-1,sym))
        return true;
    else if(rec(x+1,y-2,sym))
        return true;
    else if(rec(x+1,y+2,sym))
        return true;
    else if(rec(x-1,y-2,sym))
        return true;
    else if(rec(x-1, y+2,sym))
        return true;
    else if(rec(x-2,y-1,sym))
        return true;
    else if(rec(x-2,y+1,sym))
        return true;
    
    return false;
}


int main (int,char**)
{
    

    cin >> N >> M;
    
    
    int res=0;
    
    int Hax = 0, Hay = 0;
    int Hby = 0, Hbx = 0;
    bool Ha = false;
    
    for(int i = 0; i< N; i++)
        for(int j=0; j<M; j++)
        {
            char c;
            cin >> c;
            if(c == 'H')
            {
                if(!Ha)
                {
                    Hax = j;
                    Hay = i;
                    grid[i][j] = '.';
                    Ha=true;
                }else
                {
                    Hby = i;
                    Hbx = j;
                    grid[i][j] = '.';
                }
            }else
                grid[i][j] = c;
        }
    
    rec(Hax, Hay,'A');
    
    grid[Hay][Hax] = 'A';
  
    cout << (rec(Hbx,Hby,'B') ? "JA" : "NEJ");

    return 0;
}
