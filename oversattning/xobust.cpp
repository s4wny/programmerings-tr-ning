#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef unsigned int uint;

std::unordered_map<uint, string> itsa; //int to string
std::unordered_map<string, uint> stia; //string to int

std::unordered_map<string, uint> stib; //string to int

uint arr[50000];


int main() {
    uint N;
    
    cin >> N;
    
    N=N*2;
    
    for (uint i = 0; i<N; i=i+2) {
        string a,b;
        cin>>a>>b;
        
        uint j,k;
        
        if(stia.count(a) == 0)
        {
            itsa[i]=a;
            stia[a]=i;
            j = i+1;
        }else
        {
            j = arr[stia[a]];
        }
        
        arr[i] = j;
        
        if(stib.count(b) == 0)
        {
            stib[b]=i+1;
            k=i;
        }else
        {
            k = arr[stib[b]];
        }
        
        arr[i+1] = k;
    }
    
    // Todo länkad list arkitektur
    string result = "";
    
    unsigned long B;
    cin>>B;
    
    for (unsigned long i = 0; i<B; i++) {
        string s;
        cin >> s;
        uint w = stia[s];
        
        while (w != arr[arr[w]]) {
            w = arr[arr[w]];
        }
        if(i==B-1)
            result += itsa[w];
        else
            result += itsa[w] + " ";
    }
    
    cout<<result;
    
    return 0;
}