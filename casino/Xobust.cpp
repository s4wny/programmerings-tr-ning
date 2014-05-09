#include <iostream>

 
using namespace std;
 
 
int main() {
 
    int n,k;
        double p;
 
 
        cin >> n >> k;
        cin >> p;
 
        if( p*n >= k)
                cout<<"spela inte!";
        else
                cout<<"Spela";
 
 
 
    return 0;
}