#include <stdio.h>
 
int N, K;
 
int arr[100000];
 
 
int main() {
    
    scanf("%d %d", &N, &K);
 
        for(int i = 0; i<N; i++)
        {
                char c;
                scanf(" %c",&c);
 
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
        }
 
        int result = 0;
 
        for(int i = 0; i<N;i++)
        {
                if(arr[i] != 0)
                {
                        int dif =  4 - arr[i];
                        result += dif;
                        if(i+K <= N)
                        {
                                for(int j = i; j<i+K; j++)
                                {
                                        arr[j] += dif;
                                        if(arr[j] >= 4)
                                                arr[j] -= 4;
                                }
                        }
                        else
                        {
                                result = -1;
                                break;
                        }
                }
        }
        
        printf("%d", result);
    
    return 0;
}