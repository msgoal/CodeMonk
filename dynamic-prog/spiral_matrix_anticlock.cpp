#include<iostream>

#define CYCLE(size) ((size * 2)+((size-2) * 2))
using namespace std;


int main_antispiral(){
    int arr[6][6]={
            {1, 2, 3,  4, 5},
            {6, 7, 8,  9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}
    };

    int carr[] = {0,1,0,-1};
    int rarr[] = {1,0,-1,0};
    int size = 5,elements = size * size;
    int i=0;
    int count=0,rotation=CYCLE(size);
    int r=0,c=0;

    cout<<"  Spiral list : "<<endl;
    for(i=1;i<=elements;i++,count++){

        cout<<"   "<<arr[r][c];
        fflush(stdout);

        if(rotation > 0 && i % rotation == 0){
            size -= 2;
            rotation = rotation + CYCLE(size);
            count=-1;
        }

        r = r + rarr[((count < 0)? 0 : count)/size];
        c = c + carr[((count < 0)? 0 : count)/size];

        if( count % size == 0)
            ++count;
    }
}