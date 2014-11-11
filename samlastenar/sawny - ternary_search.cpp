/**
 * Använder trinär sökning (Ternary search).
 * http://en.wikipedia.org/wiki/Ternary_search
 *
 * O(log N)
 */

#include <cstdio>
#include <cmath>

using namespace std;

int N;
double xs[100000+1];
double ys[100000+1];

// Vår funktioner
double f(double x) {
    double dist = 0;

    // Notera att vi struntar i att ta *2 här och istället
    // gör vi det endast när vi skriver ut svaret.
    // Sparar 0.00001 micro sekunder jao
    for(int i = 0; i < N; i++)
        dist = dist + sqrt( (xs[i] - x)*(xs[i] - x) + ys[i]*ys[i] );

    return dist;
}

int main() {
    // l = 0, r = max 100. (står i uppgiften)
    // går dock att ta ut l och r snyggt i loopen när
    // vi läser in siffrorna, med min(l, xs[i]) och max(r, xs[i);
    double x, y, leftThird, rightThird, l = 0, r = 100;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lf %lf", &xs[i], &ys[i]);

    while(true) {
        if(abs(r-l) < 0.0001) // 10^-4 precision efterfrågas
            break;

        leftThird  = l + (r-l)/3;
        rightThird = r - (r-l)/3;

        if(f(leftThird) < f(rightThird))
            r = rightThird;
        else
            l = leftThird;
    }


    printf("%.5f", 2*f((r+l)/2));
}
