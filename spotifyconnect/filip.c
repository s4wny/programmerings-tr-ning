#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int play;
	int time;
} event_t;

typedef struct {
	int playTime;
	int lastAction;
	int playing;
} spotify_t;

static void swap(event_t* events, int first, int second)
{
	event_t event = events[first];
	events[first] = events[second];
	events[second] = event;
}


int main(int argc, char* argv[])
{
	int N = 0;
	scanf("%d", &N);
	spotify_t spotify;
	event_t* events = malloc(sizeof(event_t) * N);
	int currentTime = 0;
	char device[6];
	char action[5];

	spotify.playTime = 0;
	spotify.lastAction = 0;
	spotify.playing = 0;

	for(int i = 0; i < N; i++)
	{
		scanf("%d %s %s", &currentTime, &device, &action);
		
		events[i].time = currentTime;
		events[i].time += device[0] == 'm'?100:0;
		events[i].play = action[1] == 'l'? 1:0;
		int count = 0;
		do
		{
			if(i > count)
			{
				if(events[i - count].time < events[i - count - 1].time)
					swap(events, i - count, i - count - 1);
				else
					break;
			}else
				break;
			count++;
		}while(1);

	}
		
	//Evaluate

	for(int i = 0; i < N; i++)
	{
		if(events[i].play == 1 && spotify.playing != 1)
		{
			spotify.playing = 1;
			spotify.lastAction = events[i].time;
		}
		if(events[i].play == 0 && spotify.playing == 1)
		{
			spotify.playing = 0;	
			spotify.playTime += events[i].time - spotify.lastAction;
		}
	}

	free(events);
	printf("%d", spotify.playTime);
	return 0;
}

