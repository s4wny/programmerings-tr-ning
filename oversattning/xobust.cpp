#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef unsigned int uint;

std::unordered_map<uint, string> its; //int to string
std::unordered_map<string, uint> sti; //string to int


uint arr[50000];


int main() {
    uint N;
    
    cin >> N;
    
    N=N*2;
    
    for (uint i = 0; i<N; i=i+2) {
        string a,b;
        cin>>a>>b;
        
        uint j,k;
        
        if(sti.count(a) == 0)
        {
            its[i]=a;
            sti[a]=i;
            j = i+1;
        }else
        {
            j = arr[sti[a]];
        }
        
        arr[i] = j;
        
        if(sti.count(b) == 0)
        {
            its[i+1]=b;
            sti[b]=i+1;
            k=i;
        }else
        {
            k = arr[sti[b]];
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
        uint w = sti[s];
        
        while (w != arr[arr[w]]) {
            w = arr[arr[w]];
        }
        if(i==B-1)
            result += its[w];
        else
            result += its[w] + " ";
    }
    
    cout<<result;
    
    return 0;
}