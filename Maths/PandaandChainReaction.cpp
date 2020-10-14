#include <iostream>
#include "bits/stdc++.h"
#include <string.h>
using namespace std;
unsigned long long modb = 1000003;

int maint7(){
    int t;
    unsigned long long n,x;
    unsigned long long arr[1000004];
    scanf("%d",&t);
    arr[0] = 1;
    for(unsigned long long i=1;i<1000004;++i){
        arr[i] = (arr[i-1]*i)%modb;
    }
    while(t-->0){
        scanf("%lld %lld",&n,&x);
        n = (n>modb) ? 0 : x*arr[n];
        n = n%modb;
        printf("\n%lld",n);
    }
    return 0;
}
