using namespace std;

int dp[20][20];


int go(int N, int E)
{
	if(E < 0 || N<0)
		return 0; 

	if(E== 0 && N == 0)
		return 1;

	int a = 0;

	if(dp[N][E] != -1)
		return dp[N][E];
	else
	{
		for(int i = 0; i<=E; i++)
		{
			a = a + go(N-1, E-i);
		}
		dp[N][E] = a;
	}

	return a;
}


int main()
{

	int N, E;

	cin >> N >> E;


	for(int i = 0; i<20; i++)
		for(int j = 0; j<20; j++)
			dp[i][j] = -1;


	int result = 0;

	cout<<go(N,E);

	return 0;

}
