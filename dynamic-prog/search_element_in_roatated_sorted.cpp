#include <iostream>

using namespace std;

int search(int *arr,int l,int u,int key){
    int m = (l + u) / 2;

    if(l <= u){
        if(arr[m] == key)
            return m;

        if(arr[l] <= arr[m]){

            if(key >= arr[l] && key <= arr[m])
                return search(arr,l,m-1,key);
            else
                return search(arr,m+1,u,key);
        }else{

            if(key >= arr[m+1] && key <= arr[u])
                return search(arr,m+1,u,key);
            else
                return search(arr,l,m-1,key);
        }
    }
    return -1;
}

int main(){
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};

    cout<<endl<<search(arr,0,8,7);
    return 0;
}