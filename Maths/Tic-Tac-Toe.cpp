#include <bits/stdc++.h>
#include "iostream"

using namespace std;
unsigned long long int mod=1000000007;
int maindone1(){
    int t;
    scanf("%d",&t);
    while(t--){
        unsigned long long int n;
        scanf("%llu",&n);
        unsigned long long int nmod = n%mod;
        printf("\n%llu %llu",(((nmod-1)/2)*((nmod-1)/2)%mod * nmod)%mod,(((nmod - 1)%mod * nmod%mod * (2*nmod - 1)%mod * 166666668%mod))%mod);
    }
    return 0;
}