//
// Created by q on 12/28/2019.
//

#ifndef RECURSIVE_PROBLEMS_PR14_H
#define RECURSIVE_PROBLEMS_PR14_H

#endif //RECURSIVE_PROBLEMS_PR14_H
#define FREE -1
void initializeBoard(int n, int board[n][n]);
void printBoard(int n, int board[n][n]);
int isFree(int n, int board[n][n], int x, int y);
void moveKnightMoreSolutions(int n, int board[n][n], int x, int y,int *found,int moves);
int moveKnightOneSolution(int n,int board[n][n],int x,int y,int moves);
void knightsTour();