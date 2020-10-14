#include <bits/stdc++.h>
#include "iostream"

using namespace std;

int maindone2(){
    int t;
    scanf("%d",&t);
    while(t--){
        unsigned long long int n;
        scanf("%llu",&n);

        printf("\n%llu",((n-1)*((n-1)+1))/2);
    }
    return 0;
}