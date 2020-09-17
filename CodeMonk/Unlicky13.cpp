/*The Unlucky 13
Write a program to calculate the total number of strings that are made of exactly N characters.
None of the strings can have  as a substring.
The strings may contain any integer from , repeated any number of times.

Input Format
First line: T, the number of test cases.
Next T lines: Each contain an integer N.

Output Format
Print the result of each query .
Answer for each test case should come in a new line.

Constraints


        Sample Input
2
2
1
Sample Output
99
10
Time Limit: 1.0 sec(s) for each input file
        Memory Limit: 256 MB
        Source Limit: 1024 KB*/


#include <iostream>
#include <bitset>
#include <string>
#include <limits>
#include <math.h>


using namespace std;

struct Matrix{
    unsigned long long M[2][2];
};
long mod = 1000000009;
unsigned long root[40];
Matrix matrix[40];
int len;

long logval(int n)
{
    return (long)ceil(log2(n));
}

void init_Matrix(){
    unsigned long long A[2][2]={{9,8},{1,1}};
    unsigned long long I[2][2]={{1,0},{0,1}};
    matrix[0]={0};
    for(int i=1;i<=40;i++){
        matrix[i].M[0][0] = ((A[0][0]%mod * I[0][0]%mod)%mod + (A[0][1]%mod * I[1][0]%mod)%mod)%mod;
        matrix[i].M[0][1] = ((A[0][0]%mod * I[0][1]%mod)%mod + (A[0][1]%mod * I[1][1]%mod)%mod)%mod;
        matrix[i].M[1][0] = ((A[1][0]%mod * I[0][0]%mod)%mod + (A[1][1]%mod * I[1][0]%mod)%mod)%mod;
        matrix[i].M[1][1] = ((A[1][0]%mod * I[0][1]%mod)%mod + (A[1][1]%mod * I[1][1]%mod)%mod)%mod;

        A[0][0] = I[0][0] = matrix[i].M[0][0];
        A[0][1] = I[0][1] = matrix[i].M[0][1];
        A[1][0] = I[1][0] = matrix[i].M[1][0];
        A[1][1] = I[1][1] = matrix[i].M[1][1];

        /*cout<<i<<"."<<endl;
        cout<<I[0][0]<<"\t"<<I[0][1]<<endl;
        cout<<I[1][0]<<"\t"<<I[1][1]<<endl<<endl;*/
    }
}

unsigned long long** matrix_mul(){
    unsigned long long **M = new unsigned long long*[2];
    M[0] = new unsigned long long[2];
    M[1] = new unsigned long long[2];
    unsigned long long I[2][2]={{1,0},{0,1}};
    for(int i=0;i<len;i++){
        int index = logval(root[i])+1;
        M[0][0] = ((matrix[index].M[0][0]%mod * I[0][0]%mod)%mod + (matrix[index].M[0][1]%mod * I[1][0]%mod))%mod;
        M[0][1] = ((matrix[index].M[0][0]%mod * I[0][1]%mod)%mod + (matrix[index].M[0][1]%mod * I[1][1]%mod))%mod;
        M[1][0] = ((matrix[index].M[1][0]%mod * I[0][0]%mod)%mod + (matrix[index].M[1][1]%mod * I[1][0]%mod))%mod;
        M[1][1] = ((matrix[index].M[1][0]%mod * I[0][1]%mod)%mod + (matrix[index].M[1][1]%mod * I[1][1]%mod))%mod;

        I[0][0] = M[0][0];
        I[0][1] = M[0][1];
        I[1][0] = M[1][0];
        I[1][1] = M[1][1];
    }
    return (unsigned long long**)M;
}


void computePath(string bin){
    int j=0;
    for(int i=0;i<bin.length();i++){
        if(bin[i] == '1') {
            root[j++] = pow(2,bin.length()-i-1);
            //cout<<root[j]<<"  ";
        }
    }
    len = j;
}

int main(){
    long t;
    cin>>t;
    init_Matrix();
    while(t--){
        unsigned long number;
        char binary[33];
        cin>>number;
        if(number == 0){
            cout<<"1"<<endl;
            continue;
        }
        std::string s = std::bitset<std::numeric_limits<unsigned long>::digits>( number ).to_string();
        s = s.erase(0, s.find_first_not_of('0'));
        computePath(s);
        unsigned long long **m =  matrix_mul();
        cout<<(m[0][0]%mod + m[1][0]%mod)%mod<<endl;
    }

    return 0;
}