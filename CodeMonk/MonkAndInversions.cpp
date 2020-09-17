//
// Created by root on 21/08/20.
//

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int getRowPosition(int pos,int n){
    return pos/n;
}

int getColposition(int pos,int n){
    return pos%n;
}

int main2()
{
    int t;
    scanf("%d",&t);
    string s = "";
    while(t--) {
        int n;
        int arr[100005];
        cin>>n;
        for(int i=0;i<n*n;i++){
            cin>>arr[i];
        }

        int count=0;

        for(int i=0;i<n*n;i++){
            int r = getRowPosition(i,n);
            int c = getColposition(i,n);
            for(int j=0;j<n*n;j++){
                int cur_row = getRowPosition(j,n);
                int cur_col = getColposition(j,n);

                if(r <= cur_row && c <= cur_col && arr[i] > arr[j]){
                    count++;
                }
            }
        }
        s += to_string(count) + "\n";
    }

    cout<<s;
}

