
#include <iostream>

using namespace std;

unsigned long int MONK_QUOTIENT=1000000007;

long confusegcd(long a, long b)
{
    if (b == 0)
        return a;
    return confusegcd(b, a % b);

}

unsigned long int modularExponentiation(int x,int n)
{
    int p=1;
    for(int i=1;i<=n;i++){
        p = (p%MONK_QUOTIENT * x%MONK_QUOTIENT)%MONK_QUOTIENT;
    }
    return p;
}

int maindone3(){
    int N;
    scanf("%d",&N);
    unsigned long gcd=0,product=1,val;
    for(int i=1;i<=N;i++) {
        scanf("%llu",&val);
        gcd = confusegcd(gcd,val);
        product = (product%MONK_QUOTIENT * val%MONK_QUOTIENT)%MONK_QUOTIENT;

    }
    printf("\n%llu",modularExponentiation(product,gcd));
}