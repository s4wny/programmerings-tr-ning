// tävlingsprogrammeirng.cpp 
// Jag använder dijkstras sökalgoritm med en prioritetskö
//


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//Data strukturer

char arr[802][802]; //skogen
int dist[802][802][4]; //Avståndet till en punkt
bool scanned[802][802][4]; //Om en punkt har paserats med sökningen

int N, M;
int R, C;

struct bfs_data
{
    bfs_data(int a, int b, char c, int p)
	{
		x = a;
		y = b;
		dir = c;
		prio = p;
	}

	int prio; //(Avstånd)
	int x;
	int y;
	char dir; //riktning
};

//Hur datan skall prioriteras 
bool operator<(const bfs_data & a, const bfs_data & b)
{
	// notera att operatorn är vänd eftersom vi vill att lägsta värde skall vara längst upp
	return (a.prio > b.prio); 
}


std::priority_queue<bfs_data> bfsQ;


int main() {

	cin >> N >> M >> R >> C;
	
	//Skapa grafen
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char t = ' ';
			cin >> t;
			arr[j][i] = t;
			dist[j][i][0] = 99999;
			dist[j][i][1] = 99999;
			dist[j][i][2] = 99999;
			dist[j][i][3] = 99999;
			scanned[j][i][0] = false;
			scanned[j][i][1] = false;
			scanned[j][i][2] = false;
			scanned[j][i][3] = false;
		}
	}
	
	//Startpunkt för sökning
	dist[1][1][2] = 0;
	bfsQ.emplace(bfs_data(1, 1, '>', 0));

	//Dijkstra
	while (!bfsQ.empty())
	{

		int x = bfsQ.top().x;
		int y = bfsQ.top().y;    
		char dir = bfsQ.top().dir;
		bfsQ.pop();


		if (!(x > M || x<1 || y>N || y < 1))
		{

			int n_x = x, n_y = y;

			int t; //Riktnings int
			if (dir == '^')
			{
				n_y--;
				t = 0;
			}
			else if (dir == 'v')
			{
				n_y++;
				t = 1;
			}
			else if (dir == '>')
			{
				n_x++;
				t = 2;
			}
			else if (dir == '<')
			{
				n_x--;
				t = 3;
			}


			if (!scanned[x][y][t])
			{

				if (x == C && y == R)
				{
					break;
				}

				scanned[x][y][t] = true;



				if (arr[x][y] == '.')
				{
					if (!scanned[n_x][n_y][t])
					{
						if (dist[x][y][t] < dist[n_x][n_y][t])
						{
							dist[n_x][n_y][t] = dist[x][y][t];
							bfsQ.push(bfs_data(n_x, n_y, dir, dist[x][y][t]));
						}

					}
				}
				else
				{

					if (!scanned[n_x][n_y][t])
					{
						if (dist[x][y][t] < (dist[n_x][n_y][t] + 1))
						{
							dist[n_x][n_y][t] = dist[x][y][t] + 1;
							bfsQ.push(bfs_data(n_x, n_y, dir, dist[x][y][t] + 1));
						}

					}

					n_y = y;
					n_x = x;

					int n_t = -1;

					if (arr[x][y] == '^')
					{
						n_y--;
						n_t = 0;
					}
					else if (arr[x][y] == 'v')
					{
						n_y++;
						n_t = 1;
					}
					else if (arr[x][y] == '>')
					{
						n_x++;
						n_t = 2;
					}
					else if (arr[x][y] == '<')
					{
						n_x--;
						n_t = 3;
					}


					if (!scanned[n_x][n_y][n_t])
					{
						if (dist[x][y][t] < dist[n_x][n_y][n_t])
						{
							dist[n_x][n_y][n_t] = dist[x][y][t];
							bfsQ.push(bfs_data(n_x, n_y, arr[x][y], dist[x][y][t]));
						}

					}

				}
			}
		}


	}


	int min = 50000;

	for (auto i : dist[C][R])
		if (i != -1 && i < min)
			min = i;


	cout << min;

	return 0;
}
