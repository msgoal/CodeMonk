#include <iostream>
#include "bits/stdc++.h"
#include <string.h>
using namespace std;

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

void factors(long n){
    vector<int> facts;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            if(n/i == i) {
                facts.push_back(i);
            }else{
                facts.push_back(i);
                facts.push_back(n/i);
            }
        }
    }
    facts.push_back(n);
    sort(facts.begin(),facts.end());
    for (auto x : facts)
        cout << x << " ";
}

int main(){
    int n;
    long a[101]={0};
    scanf("%d",&n);
    long i=0;
    long _gcd=0,diff;
    string s="";
    scanf("%ld",&a[0]);
    for(i=1;i<n;i++){
        scanf("%ld",&a[i]);
        diff = abs((a[i] - a[i-1]));
        _gcd = gcd(_gcd,diff);
    }
    diff = abs(a[0]-a[n-1]);
    _gcd = gcd(_gcd,diff);

    factors(_gcd);
}