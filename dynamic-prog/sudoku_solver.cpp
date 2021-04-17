#include <iostream>
#include <vector>

#define MAX 9
using namespace std;

bool isfree(vector<vector<int>> &sudoku,int *r,int *c){
    int is_full = 0;

    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(sudoku[i][j] == 0)
            {
                *r = i;
                *c = j;
                is_full = 1;
                return is_full;
            }
        }
    }

    return is_full;
}

bool is_safe(vector<vector<int>> &sudoku,int num,int r,int c){

    //Row check
    int i;
    for(i=0;i<MAX;i++){
        if(sudoku[r][i] == num)
            return false;
    }

    //Col check
    for(i=0;i<MAX;i++){
        if(sudoku[i][c] == num)
            return false;
    }

    //3 X 3 box
    int row = (r / 3) * 3;
    int col = (c / 3) * 3;
    for(i=row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
            if(sudoku[i][j] == num)
                return false;
        }
    }

    return true;
}

void display_board(vector<vector<int>> &sudoku){
    cout<<"Solved SUDOKU : "<<endl<<endl;
    int r=0,c=0;
    for(auto i : sudoku){
        for(auto j : i){
            cout<<"    "<<j;
            c++;

            if(c%3 == 0){
                cout<<" ";
            }
        }
        r++;
        if(r%3 == 0)
            cout<<endl<<endl;
        else
            cout<<endl;
    }
}

bool solve(vector<vector<int>> &sudoku){
    int row,col;
    if(!isfree(sudoku,&row,&col)){
        return true;
    }
    int i;
    for(i=1;i<=MAX;i++){

        isfree(sudoku,&row,&col);

        if(is_safe(sudoku,i,row,col)){
            sudoku[row][col] = i;
            if(solve(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main_solver(){
    vector<vector<int>> sudoku{
            {0,0,0,0,7,8,0,0,9},
            {0,0,0,0,2,4,7,8,0},
            {0,0,0,0,0,0,1,0,2},
            {0,7,0,5,0,0,6,0,0},
            {6,0,2,0,8,0,5,0,3},
            {0,0,4,0,0,3,0,9,0},
            {2,0,6,0,0,0,0,0,0},
            {0,3,5,8,4,0,0,0,0},
            {4,0,0,2,5,0,0,0,0}
    };

    solve(sudoku);
    display_board(sudoku);

    //cout<<endl<<is_safe(sudoku,5,7,4);
}

