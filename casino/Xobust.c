#include <stdio.h>

int main() {
	unsigned int n,k;
	double p;
	scanf("%i %i %lf", &n, &k, &p);
	if( p*n >= k)
		printf("spela inte!");
	else
		printf("Spela");

	return 0;
}
