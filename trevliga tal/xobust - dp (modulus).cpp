
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <assert.h>  
#include <iomanip>

using namespace std;

short unsigned int arr[100001];
long dp[100001][3][2];
int N;

long rec(int mod, int i, bool sumZero)
{

	if (i == N)
	{
		if (mod == 0 && !sumZero)
			return 1;
		else
			return 0;
	}

	if (dp[i][mod][sumZero] != -1)
	{
		return dp[i][mod][sumZero];
	}

	int res = 0;

	if (arr[i] != 0 || !sumZero)
	{
		res += rec(mod, i + 1, sumZero);
	}
	else
	{
		res++;
	}

	res += rec((mod + arr[i])%3, i + 1, arr[i] != 0 ? false : sumZero);


	res = res % 1000000000;

	dp[i][mod][sumZero] = res;

	return res;
}


int main() {

	for (int i = 0; i < 100001; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -1;

	char c;
	int sum = 0;
	int i = 0;

	int a = 10000001;

	a = a % 100000000;

	cout << a;

	while (cin >> c)
	{
		sum += arr[i++] = c - '0';
	}

	N = i;
	
	cout << rec(0, 0, true);

	return 0;
}	