// Läs in alla tal, äre mobil ta + 100ms
// Sortera listan, volia nu är alla kommnadon i ordning
// Loopa igenom dem, räkna ut tiden

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
#define all(x) x.begin(), x.end()
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
 
    int N, ms, prevPlayMs = -1, prevCmdMs, totalTime = 0;
    string device, cmd, prevCmd = "paus";
    cin >> N;
 
    vector<pair<int, string>> input;
 
    for(int i = 0; i < N; i++) {
        cin >> ms >> device >> cmd;
 
        if(device == "mobile") ms += 100;   
 
        input.push_back(make_pair(ms, cmd));
    }
 
    sort(all(input));
 
    for(int i = 0; i < N; i++) {
        cmd = input[i].second;
        ms  = input[i].first;
 
        if(cmd == "paus" && prevCmd == "play") {
            totalTime += (ms - prevPlayMs);
            prevPlayMs = -1;
        }
 
        if(cmd == "play" && prevPlayMs == -1) prevPlayMs = ms;
 
        prevCmd   = cmd;
        prevCmdMs = ms;
    }
 
    cout << totalTime;
}