//
// Created by q on 12/27/2019.
//

#include "pr13.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(int m, int n, int maze[m][n]) {
    int i,j;
    srand(time(NULL));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        maze[i][j]=PASSAGE;
    for(int k=0;k<(m+n)/2;k++) {
        i=rand()%m;
        j=rand()%n;
        maze[i][j]=EMPTY;
    }
    maze[m-1][n-1]=PASSAGE;// exit is the bottom-right corner
}
void printMaze(int m, int n, int maze[m][n]) {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++)
            printf(" %d ",maze[i][j]);
        printf("\n");
    }
    printf("\n");
}
int isSafe(int m, int n, int maze[m][n], int x, int y)
{
    // if (x, y outside maze) return 0
    if (x>=0 && x<m && y>=0 && y<n && maze[x][y]==PASSAGE)
        return 1;
    return 0;
}
void initializeSolution(int m, int n, int sol[m][n]) {
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            sol[i][j]=EMPTY;
}
void move(int m,int n,int maze[m][n],int x,int y,int sol[m][n],int *found) {
    if(x==m-1 && y==n-1) {
        sol[x][y]=PASSAGE;
        printMaze(m,n,sol);
        *found=1;
        return;
        }
    if(isSafe(m,n,maze,x,y)) {
        sol[x][y]=PASSAGE;
        // move down
        if(isSafe(m,n,maze,x+1,y)==1)
            move(m,n,maze,x+1,y,sol,found);
        // move right
       if(isSafe(m,n,maze,x,y+1)==1)
           move(m,n,maze,x,y+1,sol,found);
       // clear the position of (x,y), and backtrack
        sol[x][y]=EMPTY;
    }
    return;
}

void solveMaze() {
    printf("--------------------------------------\n");
    printf("Finding our way out of a maze:\n");
    printf("Please enter the values for the size of the maze (mXn) !\n");
    int n,m;
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    printf("\n");
    int maze[m][n];
    generateMaze(m,n,maze);
    printf("The maze:\n");
    printMaze(m,n,maze);
    int sol[m][n];
    initializeSolution(m,n,sol);
    int x,y;
    int found=0;
    printf("Please enter the coordinates of the initial position (i,j) !\n"
           "Keep in mind that:\n0<=i<=%d,\t0<=j<=%d\n",m-1,n-1);
    printf("i=");
    scanf("%d",&x);
    printf("j=");
    scanf("%d",&y);
    if(x>m || y>n || maze[x][y]==0) {
        printf("Invalid coordinates.\nPlease try again!\n");
    }
    else {
        move(m, n, maze, x, y, sol, &found);
    }
    if(found==0)
        printf("No path has been found.\n");
  }