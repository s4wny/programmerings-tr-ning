#include <iostream>
#include <vector>
#include <string>
#include <map>
 
using namespace std;
 
string theMorse;
map<char, string> morseTable;       // Blazing fast
 
void go(int pos, string out) {
    string cuttedMorse = theMorse.substr(pos); // Cut cut
 
    // Important: Due to . = E and - = T we will ALWAYS get an empty string in the end, so we don't need further checks
    if(cuttedMorse == "") {
        cout << out << endl;
    }
    else {
        for(char morsesak : morseTable) { // Loop all morse things in alpha order (so we can't use an unordered_map)
            if(cuttedMorse.find(morsesak.second) == 0) { // Does our cuttedMorse starts with any valid morse?
                go(pos + morsesak.second.size(), out + morsesak.first); // If so let's cut it more!!!!
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
    string line;
    getline(cin, theMorse);
 
    for(int i = 0+'A'; i < 26+'A'; i++) {
        getline(cin, line);
        morseTable[i]  = line;          // Create morse table, key = A..Z, value = *morse* NOTE: map<> automatically sort in alpha order
    }
 
    go(0, "");
}