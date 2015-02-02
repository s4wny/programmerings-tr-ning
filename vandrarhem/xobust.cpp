#include <iostream>
#include <map>
int main()
{
    int M, N, a, b, price = 0; std::map<int, int> beds;
    std::cin >> N >> M;
    for(int i = 0; i<M; i++)
    {   std::cin >> a >>b;
        beds[a] += b;
    }
    while(N--)
    {   price += beds.begin()->first;
        if(--beds.begin()->second == 0)
            beds.erase(beds.begin());
    }
    std::cout << price; return 0;
}
