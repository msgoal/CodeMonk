#include<iostream>
#include<math.h>

using namespace std;
int a[1000001],p[1000001];

/*void get(int *z)
{
    char c=getchar_unlocked();
    for(*z=0;c>47 && c<58;c=getchar_unlocked())
        *z=*z*10+c-'0';
}*/

void primer()
{
    int i,j;
    for(i=2;i<1000001;i++)
    {
        j=1;
        if(a[i])
        {
            p[i]=p[i-1];
            continue;
        }
        else
            p[i]=p[i-1]+1;
        for(;j*i<1000001;j++)
            a[j*i]=1;

        printf("%d, ",p[i]);
    }
}

int maindone5(){
    long long int Q;
    int count=0;
    long long int L,R;
    scanf("%lld",&Q);
    primer();
    while(Q--){
        scanf("%lld%lld",&L,&R);
        if(L > R)
            printf("%d",p[L]-p[R-1]);
        else
            printf("%d",p[R]-p[L-1]);
    }

    return 0;
}