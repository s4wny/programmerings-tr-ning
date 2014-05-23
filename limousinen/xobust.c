#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
 
 
int main() {
    int N;
        long T;
        long arr[100000];
        scanf("%d %dl", &N, &T);
 
        for(long i = 0; i < N; i++)
        {
                long x,y;
                scanf("%li %li",&x,&y);
                arr[i] = abs(x) + abs(y);
        }
 
        qsort(&arr,N,sizeof(long), cmpfunc);
 
        long ans = 0;
 
        for(long i = 0; i < N; i++)
        {
                T -= arr[i]*2;
                if(T<0)
                        break;
                else
                        ans++;
        }
 
        printf("%li", ans);
 
        return 0;
}