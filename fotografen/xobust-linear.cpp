#include <iostream>
#include <vector>
 
using namespace std;

/*
Lösning:
Ladda in värdena som ints i en array(se switch satsen)
Fyll en andra aray med 0 or.

Varje gång du stöter på en blid som ska roteras gör föjande
läg till den krävd rotationen till den nuvarande rotationens 
variable och läg till att roationen ska minska vid i+k.

Rotera bilden varje iteration om du inte kan rotera en bild 
så är svaret minus 1
 

*/

 
int N, K;
 
std::vector<int> arr;
std::vector<int> rot_dif;
 
inline void add(int &a, int &b)
{
    a+=b;
    if(a >= 4)
    	a-=4;
	else if (a<0)
		a+=4;
}
 
 
int main() {
    
    std::cin.sync_with_stdio(false);
 
    int c_rot = 0;
    
    cin >> N >> K;
 
    for(int i = 0; i<N; i++)
    {
        char c;
        cin >> c;
 
        switch (c)
        {
        case 'U':
                arr.push_back(0);
                break;
        case 'V':
                arr.push_back(3);
                break;
        case 'H':
                arr.push_back(1);
                break;
        case 'N':
                arr.push_back(2);
                break;
        }
        rot_dif.push_back(0);
    }
 
    int result = 0;
 
    for(int i = 0; i<N;i++)
    {
        add(arr[i],c_rot);
 
        if(arr[i] % 4 != 0)
        {
            int dif =  4 - arr[i];
            result += dif;
            add(c_rot,dif);
 
            if(i+K <= N)
            {
                rot_dif[i+K-1] = -dif;  
            }
            else
            {
                result = -1;
                break;
            }
        }
 
        add(c_rot,rot_dif[i]);
    }
        
    cout<< result;
    
    return 0;
}