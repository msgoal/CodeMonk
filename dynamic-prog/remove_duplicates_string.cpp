#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char* eliminate_duplicates_forloop(char *src,char *dest){
    int index=0;
    while (*src != NULL){
        int j;
        for(j = 0;j <= index; j++){
            if(dest[j] == *src){
                j = 0;
                break;
            }
        }
        if(j){
            index = j;
            dest[j-1] = *src;
        }
        src++;
    }
    return dest;
}

char* eliminate_duplicates_hashmethod(char *src,char *dest){
    bool hash[255]={0};
    int i=0;
    while(*src != NULL){
        if(!hash[*src]){
            dest[i++] = *src;
            hash[*src] = true;
        }
        src++;
    }

    return dest;
}


int main_eliminate_duplicate_chars(){
    char src[] = "VIJAYKUMARAJAY";
    int n = (int)(sizeof (src) /sizeof (char));
    cout<<endl<<"Size : "<<sizeof (src)<<" and Size of Char : "<<sizeof (char);
    char *dest = new char[n];

    cout<<" Dest str : "<<eliminate_duplicates_hashmethod(src,dest);

}

