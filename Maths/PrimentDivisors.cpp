#include<iostream>
#include <bits/stdc++.h>
#include<math.h>

using namespace std;

long long countoffactors(long long n){
    int count=0;
    int result = 1,pc=0;
    for(long i=2;i<=sqrt(n);i++){
        count=1;
        if(n%i==0)pc++;
        while(n%i == 0){
            count++;
            n /= i;
        }
        result *= count;
    }
    return ((n > 1)? (result*2)-(pc+1) : result-(pc));
}

int mainsa(){
    long long t;
    scanf("%lld",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        cout<<endl<<countoffactors(n);
    }
}