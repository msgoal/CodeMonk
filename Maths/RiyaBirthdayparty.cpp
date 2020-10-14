#include <bits/stdc++.h>
#include "iostream"

using namespace std;

unsigned long long rmod = 1000000007;
int mainza(){
    long t;
    scanf("%ld",&t);

    while(t--){
        unsigned long long int n;
        scanf("%llu",&n);

        printf("\n%llu",(n%rmod)*(2llu * n%rmod - 1llu)%rmod);
    }
    return 0;
}

