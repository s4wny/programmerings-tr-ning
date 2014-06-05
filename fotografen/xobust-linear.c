#include <stdio.h>
 
int N, K;
 
int arr[100000];
int rot_dif[100000];
 
 
int main() {

    int c_rot = 0;
    
    scanf("%d %d", &N, &K);
 
    for(int i = 0; i<N; i++)
    {
        char c;
        scanf(" %c", &c);
 
        switch (c)
        {
        case 'U':
                arr[i] = 0;
                break;
        case 'V':
                arr[i] = 3;
                break;
        case 'H':
                arr[i] = 1;
                break;
        case 'N':
                arr[i] = 2;
                break;
        }
        rot_dif[i] = 0;
    }
 
    int result = 0;
 
    for(int i = 0; i<N;i++)
    {
    	arr[i]+=c_rot;
		if(arr[i] >= 4) //första preioden
			arr[i]-=4;
 
		if(arr[i] % 4 != 0)
        {
            int dif =  4 - arr[i];
            result += dif;
            c_rot+=dif;
			if(c_rot >= 4) //första preioden
				c_rot-=4;
 
            if(i+K <= N)
            {
                rot_dif[i+K-1] = -dif;  
            }
            else
            {
                result = -1;
                break;
            }
        }
 
        c_rot+=rot_dif[i];
		if(c_rot<0)//första preioden
			c_rot += 4;
    }
        
    printf("%d", result);
    
    return 0;
}