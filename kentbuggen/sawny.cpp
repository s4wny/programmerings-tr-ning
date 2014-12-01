#include <iostream>
#include <string>
#include <unordered_map>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    
    int N, counter = 0;
    string name;
    unordered_map<string, int> names;
 
    cin >> N;
    while(!(cin >> name).eof())
        ++names[name];
 
    for(auto name : names)
        if(name.second > 1)
            counter++;
 
    cout << counter;
}