//
// Created by q on 12/28/2019.
//

#include "pr14.h"
#include <stdio.h>

void initializeBoard(int n, int board[n][n]) {
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        board[i][j]=FREE;
}
void printBoard(int n, int board[n][n]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf(" %d ",board[i][j]);
        printf("\n");
    }
    printf("\n");
}
int isFree(int n, int board[n][n], int x, int y)
{
    // if (x, y outside chessboard) return 0
    if (x>=0 && x<n && y>=0 && y<n && board[x][y]==FREE)
        return 1;
    return 0;
}

int moveKnightOneSolution(int n,int board[n][n],int x,int y,int moves) {
    if(moves==n*n) {
        board[x][y]=moves;
        return 1;
    }
    int xNext,yNext,xMove[8]={-2,-2,-1,-1,1,1,2,2},yMove[8]={-1,1,-2,2,-2,2,-1,1};

    if(isFree(n,board,x,y)==1) {
        board[x][y] = moves;
        for (int k = 0; k < 8; k++) {
            xNext = x + xMove[k];
            yNext = y + yMove[k];
            if(isFree(n,board,xNext,yNext)==1 && moveKnightOneSolution(n, board, xNext, yNext, moves + 1) == 1)
                return 1;
        }
        board[x][y] = FREE;
    }

    return 0;
}

void moveKnightMoreSolutions(int n,int board[n][n],int x,int y,int *found,int moves) {
    if(moves==n*n) {
        board[x][y]=moves;
        printBoard(n,board);
        *found=1;
        return;
    }
    int xNext,yNext,xMove[8]={-2,-2,-1,-1,1,1,2,2},yMove[8]={-1,1,-2,2,-2,2,-1,1};

    if(isFree(n,board,x,y)==1) {
      board[x][y] = moves;
      for (int k = 0; k < 8; k++) {
          xNext = x + xMove[k];
          yNext = y + yMove[k];
          if(isFree(n,board,xNext,yNext)==1)
             moveKnightMoreSolutions(n, board, xNext, yNext, found, moves + 1);
      }
      board[x][y]=FREE;
    }
    return;
}

void knightsTour() {
    printf("--------------------------------------\n");
    printf("Knight's tour on a chessboard, so that each cell is reached only once.\n");
    int n;
    printf("Please enter the size of the chessboard (nXn)!\nn=");
    scanf("%d", &n);
    getchar();
    int board[n][n], moves = 1;
    initializeBoard(n, board);
    printf("Do you want to generate 1 solution or all of them?\na)one\nb)all\n");
    char c = getchar();
    if (c == 'a') {
        if (moveKnightOneSolution(n, board, 0, 0, moves) == 1)
            printBoard(n, board);
        else
            printf("Not possible!\n");
    } else {
        if (c == 'b') {
            int found = 0;
            moveKnightMoreSolutions(n, board, 0, 0, &found, moves);
            if (found == 0)
                printf("No solutions have been found.\n");
        } else
            printf("Invalid choice.\n");
    }
}
