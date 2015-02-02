#include <iostream>
#include <map>
using namespace std;
int main()
{
    int M, N, a, b, p = 0,i; map<int, int> d;
    cin >> N >> M;
    for(i = 0; i<M; i++)
    {   cin >> a >>b;
        d[a] += b;
    }
    while(N--)
    {   p += d.begin()->first;
        if(--d.begin()->second == 0)
            d.erase(d.begin());
    }
    cout << p;
}
