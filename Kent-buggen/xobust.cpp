
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

map<string, int> m;

void test(string n)
{
    
    if(m.find(n) == m.end())
        m[n] = 0;
    else
        m[n]=1;
    
}

int main (int,char**)
{

    std::ios_base::sync_with_stdio(false);

    
    int N;
    cin >> N;
    
    
    int res=0;
    
    while(N--)
    {
        string namn;
        cin >> namn;
        test(namn);
    }

    
    
    for(auto A : m)
        res+=A.second;
    
    cout << res;

    return 0;
}
