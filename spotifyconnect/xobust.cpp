
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

int main (int,char**)
{
    
    int N;
    cin >> N;
    
    int start = 0;
    bool play = false;
    int res = 0;
    
    while(N--)
    {
        int t;
        string dev, type;
        
        cin >> t >> dev >> type;
         if(dev=="mobile")
             t += 100;
      
        pq.push(ent(t,type));

        
    }
    
    while (!pq.empty()) {
        
        
        if(pq.top().type == "play" &&play == false)
        {
            start = pq.top().t;
            play = true;
        }
        
        if(pq.top().type == "paus" && play == true)
        {
            
            res += pq.top().t - start;
            play = false;
        }
        
        pq.pop();
        
    }
    
    
    cout << res;

    return 0;
}
