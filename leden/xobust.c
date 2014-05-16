//
//  main.cpp
//  brädspelet
//
//  Created by Alexander Bladh on 2014-05-07.
//  Copyright (c) 2014 ab. All rights reserved.
//

#include <stdio.h>
#include <math.h>


int main()
{
    int N;
    scanf("%d",&N);
    
    int tid = 0;
    
    int current;
    scanf("%d",&current);
    
    for(int i = 0; i<N; i++)
    {
        int now;
        scanf("%d",&now);
        
        tid += 60;
        tid += fabs(5+(now-current))*2;
        
        current = now;
    }
    
    
    printf("%d",tid);
    
    
    return 0;
}

