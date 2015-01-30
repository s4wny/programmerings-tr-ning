#include <stdio.h>
#include <stdlib.h>

static int jump(char** board, int x, int y, int N, int K)
{
	if(x < 0 || x >= K || y < 0 || y >= N) return 0;
	if(board[y][x] == '#' || board[y][x] == '\0')return 0;
	if(board[y][x] == 'H')return 1;
	board[y][x] = '\0';
	return jump(board, x - 2, y -  + 1, N, K) + jump(board, x - 1, y - 2, N, K) + jump(board, x + 1, y - 2, N, K) + jump(board, x + 2, y - 1, N, K) + jump(board, x + 2, y + 1, N, K) + jump(board, x + 1, y + 2, N, K) + jump(board, x - 1, y + 2, N, K) + jump(board, x - 2, y + 1, N, K); 
}



int main(void)
{
	int N, K;
	int x, y;
	scanf("%d %d", &N, &K);
	char** board = malloc(sizeof(char *) * N);
	for(int i = 0; i < N; i++)
		board[i] = malloc(sizeof(char) * K);

	for(int i = 0; i < N; i++)
	{
		scanf("%c", &board[i][0]);
		for(int j = 0; j < K; j++)
		{
			scanf("%c", &board[i][j]);
			if(board[i][j] == 'H')
			{
				x = j;
				y = i;
			}
		}
	}
	board[y][x] = '.';
	int ret = jump(board, x, y, N, K);
	if(ret > 0)
		printf("JA");
	else
		printf("NEJ");
	return 0;
}
