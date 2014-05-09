#include <stdio.h>

#define N	9;

int main() {
	
	int arr[N];
	int sum = 0;

	for(int i = 0; i<N; i++)
	{
		scanf("%d",&arr[i]);
	}

	for(int i = 0; i<N; i=i+2)
	{
		sum = sum + arr[i] * 3;
	}

	for(int i = 1; i<N; i=i+2)
	{
		sum = sum + arr[i] * 7;
	}

	printf("%i",sum%10);

	return 0;
}