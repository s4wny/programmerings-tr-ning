#include <iostream>

using namespace std;

int dp[100][100]; //vinner personen som gör nästa drag om spelplanen just nu är [width][height] stor?

int Do(int w, int h)
{
	if (dp[w][h] != -1) return dp[w][h];

	bool ret = false;

	if (w == 1 && h == 1)
		return 0; //spelaren vars tur det är nu förlorar

	//dela på alla x
	for (int i = 1; i < w; ++i)
		if (ret)
			break;
		else
			ret = !Do(i, h) && !Do(w - i, h); //om man vinner på båda de här bitarna så vinner man

	//dela på alla y
	for (int i = 1; i < h; ++i)
		if (ret)
			break;
		else
			ret = !Do(w, i) && !Do(w, h - i);

	return dp[w][h] = ret;
}

int main()
{
	////
	cin.sync_with_stdio(false);
	cin.tie(0);
	//// Programmet misslyckas skumt nog på ett enda testfall om jag tog bort de här två raderna, kan någon förklara det skulle jag bli glad :)

	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			dp[i][j] = -1;

	int n, m;
	cin >> n >> m;

	if (Do(n, m))
		cout << "A\n";
	else
		cout << "B\n";

	return 0;
}