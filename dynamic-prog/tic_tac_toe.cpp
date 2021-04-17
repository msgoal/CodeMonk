#include<iostream>

#define MAXLENGTH 9
#define PLAYER_MOVE(val) (val)? 'X' : 'O'
#define WINNER_SCORE 10
#define OPPONENT_SCORE -10
#define DRAW_MATCH 0
#define MINMAX(val) (val)? INT16_MIN : INT16_MAX

using namespace std;

void print(const char tboard[]){
    int i;
    cout<<endl<<" Current state : "<<endl<<endl;
    cout<<" ----+---+----"<<endl;
    for(i=0;i<MAXLENGTH;i++){
        cout<<" | "<<tboard[i];
        if((i+1)%3 == 0) {
            cout << " | " << endl;
            cout << " ----+---+----" << endl;
        }
    }
}

bool iswin(const char aboard[MAXLENGTH], char move){
    int winarr[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };

    for(int i=0;i<8;i++){
        if(aboard[winarr[i][0]] != ' ' && aboard[winarr[i][0]] == move &&
        aboard[winarr[i][0]] == aboard[winarr[i][1]] &&
        aboard[winarr[i][0]] == aboard[winarr[i][2]]){
            return true;
        }
    }
    return false;
}

int minimax(char aboard[MAXLENGTH],bool iscomp){

    if(iswin(aboard,PLAYER_MOVE(!iscomp))){
        return (!iscomp)? WINNER_SCORE : OPPONENT_SCORE;
    }

    int score = MINMAX(iscomp);
    int move = -1;

    for(int i=0;i<MAXLENGTH;i++){
        if(aboard[i] == ' ') {
            aboard[i] = PLAYER_MOVE(iscomp);

            int tempscore = minimax(aboard, !iscomp);
            aboard[i] = ' ';

            if(iscomp){
                if(tempscore > score){
                    score = tempscore;
                    move = i;
                }
            }else{
                if(tempscore < score){
                    score = tempscore;
                    move = i;
                }
            }
        }
    }
    //cout<<endl<<move;
    if(move == -1)
        return DRAW_MATCH;

    return score;
}

void compmove(char aboard[MAXLENGTH]){
    int move = -1;
    int score = INT16_MIN;

    for(int i=0;i<MAXLENGTH;i++){
        if(aboard[i] == ' '){
            aboard[i] = 'X';
            int tempscore = minimax(aboard, false);
            aboard[i] = ' ';

            if(tempscore > score){
                score = tempscore;
                move = i;
            }
        }
    }
    aboard[move] = 'X';
}

void playermove(char aboard[MAXLENGTH]){
    const int row_length=3;
    int r, c;
    bool isvalid=true;
    do {
        cout << endl << " Human : 'O' & Computer : 'X' ";
        cout << endl << " Enter row and col : ";
        cin >> r >> c;
        isvalid = r < 1 || r > row_length || c < 1 || c > row_length || aboard[(row_length * (r - 1)) + (c - 1)] != ' ';
        if(!isvalid)
        aboard[(row_length * (r - 1)) + (c - 1)] = 'O';
    }while(isvalid);
}

int main_ttt(){
    char board[] ={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int bord[] = {-1,0,1,1,0,0,1,-1,-1};
    char ai = 'X',human='O';
    int val;
    bool isComp=true;
    cout<<endl<<" PRESS 1 to start First else PRESS 0 : "<<endl;
    cin>>val;
    isComp = !val;
    for(int i=1;i<=MAXLENGTH;i++){
        if(isComp){
            compmove(board);
        }else{
            print(board);
            playermove(board);
        }
        isComp = !isComp;
    }

    //cout<<endl<<minimax(board,true);
    //compmove(board);
    print(board);

    return 0;
}
