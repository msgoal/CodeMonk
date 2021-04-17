#include <iostream>
#include <math.h>
#include<bits/stdc++.h>

#define MAX_ELEMENTS(inp) (int)(sizeof(inp)/sizeof(inp[0]))
//if heap has from 2^i to 2^(i+1) - 1 nodes it's height will be i
using namespace std;
int MAX;

int minimaxO(int inp[],int nodeIndex,bool isMaximizer,int depth){

    if(depth == 0){
        return inp[nodeIndex-MAX];
    }

    if(isMaximizer) {
        return max(minimaxO(inp, (2 * nodeIndex) + 1, false, depth - 1),
                   minimaxO(inp, (2 * nodeIndex) + 2, false, depth - 1));
    }else{
        return min(minimaxO(inp, (2 * nodeIndex) + 1, true, depth - 1),
                   minimaxO(inp, (2 * nodeIndex) + 2, true, depth - 1));
    }
}

int mainMiniMaxwitharraynumbers(){
    //int inp[8] = {3, 5, 2, 9, 12, 5, 23, 23};
    int inp[3]={3,5,2};
    MAX = MAX_ELEMENTS(inp)-1;
    int depth = log2(MAX+1);

    cout<<endl<<" Move : "<<minimaxO(inp,0,true,depth);
    return 0;
}