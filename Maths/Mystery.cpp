#include<iostream>
#include <bits/stdc++.h>
#include<math.h>

using namespace std;

long countoffactors(long n){
    int count=0;
    int result = 1;
    for(int i=2;i<=sqrt(n);i++){
        int count=1;
        while(n%i == 0){
            count++;
            n /= i;
        }
        result *= count;
    }
    return (n > 1)? (result*2) : result;
}

int mainv(){
    /*long t;
    scanf("%ld",&t);
    while(t--){
        long n;
        scanf("%ld",&n);
        cout<<endl<<countoffactors(n);
    }*/
    long n;
    cin>>n;
    //factors(n);
}