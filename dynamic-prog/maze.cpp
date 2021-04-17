#include <iostream>

#define MAX 5

using namespace std;
int result[MAX][MAX] = {0};

int find_path(int maze[MAX][MAX],int r,int c){
    int x;
    if(r == MAX-1 && c == MAX-1 && maze[r][c] == 1) {
        result[r][c] = 1;
        return 1;
    }
    if(maze[r][c] == 0 || (c == MAX && r < MAX-1))
        return 0;


    result[r][c] = 1;
    x = find_path(maze,r,c+1);
    if(x == 0)
        x = find_path(maze,r+1,c);

    return x;
}

void print_solution(){
    int i;
    for(i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<"  "<<result[i][j];
        }
        cout<<endl;
    }
}

int main_maze(){
    int maze[MAX][MAX]= {
            {1,0,0,1,1},
            {1,1,1,1,0},
            {1,1,0,1,0},
            {0,0,1,1,0},
            {1,1,1,1,1}
    };

    if(find_path(maze,0,0))
        print_solution();
    else
        cout<<endl<<"Invalid Maze.";

    return 0;
}