#include <iostream>
 
using namespace std;
 
 
 
int main()
{
 
    int n;
        cin >> n;
 
        for (int i = 0; i < n; i++)
        {
                int hh, mm, st, sn;
 
                cin >> hh >> mm >> st >> sn;
 
                mm += hh * 60;
 
                mm += st*sn;
 
                if (mm  >= 7*60)
                {
                        cout << i + 1 << " ";
                }
        }
 
        return 0;
}