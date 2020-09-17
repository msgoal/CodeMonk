#include<bits/stdc++.h>
using namespace std;
int main1()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        int arr[100005];
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        k%=n;
        printf("%d ",k);
        for(int i=0;i<n;i++)
            printf("%d ",arr[(i+(n-k))%n]);
        printf("\n");
    }
    return 0;
}