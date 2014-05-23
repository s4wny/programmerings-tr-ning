#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long N,T;
	long arr[100000];
	cin >> N >>T;

	for(long i = 0; i < N; i++)
	{
		long x,y;
		cin>>x>>y;
		arr[i] = abs(x) + abs(y);
	}

	std::sort(arr,arr + N);

	long ans = 0;

	for(long i = 0; i < N; i++)
	{
		T -= arr[i]*2;
		if(T<0)
			break;
		else
			ans++;
	}

	cout << ans;

	return 0;
}
