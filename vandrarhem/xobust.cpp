#include <iostream>
#include <map>
int main()
{
    int M, N, a, b, price = 0,i; std::map<int, int> d;
    std::cin >> N >> M;
    for(i = 0; i<M; i++)
    {   std::cin >> a >>b;
        d[a] += b;
    }
    while(N--)
    {   price += d.begin()->first;
        if(--d.begin()->second == 0)
            d.erase(d.begin());
    }
    std::cout << price; return 0;
}
