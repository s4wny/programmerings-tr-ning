#include <stdio.h>
#include <stdlib.h>
 
 /* a more C ish solution with C input and vintage qsort, it is realy fast*/
 
 
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
 
 
int main() {
    int N;
        long T;
        long arr[100000];
        scanf("%d %ld", &N, &T);
 
        for(int i = 0; i < N; i++)
        {
                long x,y;
                scanf("%ld %ld",&x,&y);
                arr[i] = abs(x) + abs(y);
        }
 
        qsort(&arr,N,sizeof(long), cmpfunc);
 
        int ans = 0;
 
        for(int i = 0; i < N; i++)
        {
                T -= arr[i]*2;
                if(T<0)
                        break;
                else
                        ans++;
        }
 
        printf("%i", ans);
 
        return 0;
}
