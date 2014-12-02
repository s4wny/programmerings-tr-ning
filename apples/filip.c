#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) (x>y?x:y)


int plockApples(int** trees, int x, int y, int K, int* N, int vertical);

int main (int argc, char* argv[])
{
	int N = 0, K = 0;
	int** trees;
	scanf("%d %d", &N, &K);
	trees = (int **)malloc(sizeof(int*) * 2);
	trees[0] = (int *)malloc(sizeof(int)*N);
	trees[1] = (int *)malloc(sizeof(int)*N);

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &trees[i][j]);
			
	printf("%d", plockApples(trees, 0, 1, K, &N, 0));
	free(trees[0]);
	free(trees[1]);
	free(trees);
	return 0;
}

int plockApples(int** trees, int x, int y, int K, int* N, int vertical)
{
	if(y < 0 || y > 1 || x < 0 || x >= *N) return 0;
	K--;
	if(K <= 0)return trees[y][x];
	int numApples = plockApples(trees, x + 1, y, K, N, 0);
	if(!vertical)
	{
		numApples = MAX(numApples, plockApples(trees, x, y + 1, K, N, 1));
		numApples = MAX(numApples, plockApples(trees, x, y - 1, K, N, 1));
	}
	return numApples + trees[y][x];
}

