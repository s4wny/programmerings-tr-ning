// tävlingsprogrammeirng.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int N, L;

int DP[62][62][62][62];

int q[200];

int rec(int n, int fil1, int fil2, int fil3,int fil4)
{

	if (n >= N)
		return n;

	if (DP[fil1][fil2][fil3][fil4])
		return DP[fil1][fil2][fil3][fil4];
	else
		DP[fil1][fil2][fil3][fil4] = n;

	int c = q[n];

	int pp, p = n;

	int d = c;
	if (fil1 != L)
		d++;

	if (fil1 >= d)
	{
		pp = rec(n + 1, fil1 - d, fil2, fil3, fil4);
	
		if (pp > p)
			p = pp;
	}

	d = c;
	if (fil2 != L)
		d++;

	if (fil2 >= d)
	{
		pp = rec(n + 1, fil1, fil2 - d, fil3, fil4);
		
		if (pp > p)
			p = pp;
	}

	d = c;
	if (fil3 != L)
		d++;

	if (fil3 >= d)
	{
		pp = rec(n + 1, fil1, fil2, fil3 - d, fil4);
	
		if (pp > p)
			p = pp;
	}

	d = c;
	if (fil4 != L)
		d++;

	if (fil4 >= d)
	{
		pp = rec(n + 1, fil1, fil2, fil3, fil4 - d);

		if (pp > p)
			p = pp;
	}


	return p;
}



int main()
{

	std::ios_base::sync_with_stdio(false);

	memset(DP, 0, 62 * 62 * 62 * 62 * sizeof(int));

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		q[i] = a;

	}

	cout << rec(0, L, L ,L, L);


	return 0;
}