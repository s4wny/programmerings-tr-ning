
#include <iostream>
#include <math.h>
#include <queue>
#include <iomanip>

using namespace std;


struct ent
{
    
    ent(int a, int b)
    {
        left = b;
        right = a;
    }
    
    int left;
    int right;

    
};

struct Comp{
    bool operator()(const ent& a, const ent& b){
        return a.left>b.left;
    }
};



priority_queue<ent, vector<ent>, Comp> pq;


int N;

int main() {
    
    long double res = 0;
    
    std::ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    while(N--)
    {
        int x;
        int y;
        cin >> x >> y;
        res += y*y;
        pq.push(ent(x+abs(y), x-abs(y)));
    }
    
    ent prev = pq.top();
    pq.pop();
    
    while (!pq.empty()) {
        
        
        if(pq.top().left < prev.right)
        {
            
            if(pq.top().right < prev.right)
                res -= (pq.top().right - pq.top().left)/2.0f * (pq.top().right - pq.top().left)/2.0f;
            else
            {
                res -= (prev.right - pq.top().left)/2.0f * (prev.right - pq.top().left)/2.0f;
                prev=pq.top();
            }
        }else
        {
            prev=pq.top();
        }
    
        
        pq.pop();
    }
    
    
    cout<<std::setprecision(12)<<res;
    
    
    return 0;
}