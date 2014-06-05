#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

std::unordered_map<int, string> itsa; //int to string
std::unordered_map<string, int> stia; //string to int

std::unordered_map<string, int> stib; //string to int

std::vector<int> arr;
std::vector<int> sav;


inline const int rec(int & w)
{
    if(sav[w] != -1)
        return sav[w];
    
    if(w == arr[arr[w]])
    {
        return w;
    }else
    {
        sav[w] = rec(arr[arr[w]]);
        return sav[w];
    }
  
}



int main() {
    
    std::cin.sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    N=N*2;
    
    for (int i = 0; i<N; i=i+2) {
        string a,b;
        cin>>a>>b;
        
        int j,k;
        
        if(stia.count(a) == 0)
        {
            itsa[i]=a;
            stia[a]=i;
            j = i+1;
        }else
        {
            j = arr[stia[a]];
        }
        
        arr.push_back(j);
        
        if(stib.count(b) == 0)
        {
            stib[b]=i+1;
            k=i;
        }else
        {
            k = arr[stib[b]];
        }
        
		arr.push_back(k);
        
        sav.push_back(-1);
        sav.push_back(-1);
    }
    
    // Todo länkad list arkitektur
    string result = "";
    
    unsigned long B;
    cin>>B;
    
    for (unsigned long i = 0; i<B; i++) {
        string s;
        cin >> s;
        
        int w = rec(stia[s]);
        
        if(i==B-1)
            result += itsa[w];
        else
            result += itsa[w] + " ";
    }
    
    cout<<result;
    
    return 0;
}
