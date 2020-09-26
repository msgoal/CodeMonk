#include<iostream>

using namespace std;

long dec2base9(long N) {

    if(N<9)
        return N;
    return N%9 + 10*dec2base9(N/9);
}

int main21(){
    long n;
    while(cin>>n){

        cout<<dec2base9(n)<<endl;
    }
    return 0;
}