//
//  main.cpp
//  brädspelet
//
//  Created by Alexander Bladh on 2014-05-07.
//  Copyright (c) 2014 ab. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int tid = 0;
    
    int current;
    cin>> current;
    for(int i = 0; i<N; i++)
    {
        int now;
        cin >> now;
        
        tid += 60;
        tid += abs(5+(now-current))*2;
        
        current = now;
    }
    
    
    cout<<tid;
    
    
    
    return 0;
}

