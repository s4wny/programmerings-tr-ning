#include <iostream>
#include <string.h>

#define H 17
#define W 10000000

using namespace std;

int N, E;
int memo[H][W];

int recur(int round, int sum) {
    int c = 0;
    int tmpsum = 0;

    if(round == 0) {
        if(sum == E) return 1;
        else         return 0;
    }

    for(int i = 0; i <= E; i++) {
        if((sum + i) > E) break;

        tmpsum = i+sum;
        if(memo[round - 1][tmpsum] == -1)
            memo[round - 1][tmpsum] = recur(round - 1, tmpsum);

        c += memo[round - 1][tmpsum];
    }

    return c;
}

int main () {
    cin >> N >> E;
    memset(memo, -1, sizeof(memo[0][0])*H*W);

    cout << recur(N, 0) << endl;
}