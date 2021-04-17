#include <iostream>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

typedef struct Disc{
    char src;
    char dest;
    char aux;
    int no_of_disc;
}Disc;
int count=0;
stack<Disc> stk;

Disc set(int no_of_disc, char src, char dest, char aux){
    Disc *ptr = new Disc;
    ptr->dest = dest;
    ptr->src = src;
    ptr->aux = aux;
    ptr->no_of_disc = no_of_disc;

    return *ptr;
}

void solve(int no_of_disc,char source,char dest, char aux){

    //cout<<"SRC : "<<source<<" Dest : "<<dest<<" AUX : "<<aux<<endl;
    if(no_of_disc == 1) {
        cout <<endl<<++count<<". Move disc 1 from " << source << " to " << dest;
        return;
    }

    solve(no_of_disc-1, source, aux, dest);

    cout<<endl<<++count<<" Move disc "<<no_of_disc<<" from "<<source<<" to "<<dest;

    solve(no_of_disc-1, aux, dest, source);
}


void solveLoop(int nd,char source,char dest, char aux){
    char tsrc = source,tdest = dest, taux = aux,no_of_disc = nd;
    int cnt=0;
    while(1) {
        for (int i = no_of_disc; i >= 1; i--) {
           stk.push(set(i,tsrc,tdest,taux));

           tdest = stk.top().aux;
           taux = stk.top().dest;
           cout<<endl<<"Total Count of Inerations : "<<++cnt;
        }

        Disc topDisc = stk.top();
        //cout << endl << ++count << ". Move disc " << topDisc.no_of_disc << " from " << topDisc.src << " to " << topDisc.dest;
        stk.pop();

        if (!stk.empty()){
            topDisc = stk.top();
            //cout << endl << ++count << ". Move disc " << topDisc.no_of_disc << " from " << topDisc.src << " to "<< topDisc.dest;
            stk.pop();
        }
        fflush(stdout);

        no_of_disc = topDisc.no_of_disc-1;
        tsrc = topDisc.aux;
        tdest = topDisc.dest;
        taux = topDisc.src;

        if(count == (int)pow(2,nd)-1)
            return;
    }
}


int mainTOH(){

    solveLoop(8,'A','C','B');

    return 0;
}
