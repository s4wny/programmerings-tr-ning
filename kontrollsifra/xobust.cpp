#include <iostream>

#define N	9

using namespace std;

int main() {
	
	int arr[N];
	int sum = 0;

	for(int i = 0; i<N; i++)
	{
		cin>> arr[i];
	}

	for(int i = 0; i<N; i=i+2)
	{
		sum = sum + arr[i] * 3;
	}

	for(int i = 1; i<N; i=i+2)
	{
		sum = sum + arr[i] * 7;
	}

	cout<<sum%10;

	return 0;
}