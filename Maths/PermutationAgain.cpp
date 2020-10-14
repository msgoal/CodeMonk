#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long int

int maindone6()
{
    int t;
    ll n, z;
    cin >> t;
    while (t--) {
        scanf("%llu",&n);
        z = (n * n)/2;
        printf("%llu\n",labs(z-1));
    }

    return 0;
}