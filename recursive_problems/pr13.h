//
// Created by q on 12/27/2019.
//

#ifndef RECURSIVE_PROBLEMS_PR13_H
#define RECURSIVE_PROBLEMS_PR13_H

#endif //RECURSIVE_PROBLEMS_PR13_H
#define EMPTY 0
#define PASSAGE 1
void generateMaze(int m, int n, int maze[m][n]);
void printMaze(int m, int n, int maze[m][n]);
int isSafe(int m, int n, int maze[m][n], int x, int y);
void initializeSolution(int m, int n, int sol[m][n]);
void move(int m, int n, int maze[m][n], int x, int y, int sol[m][n],int *found);
void solveMaze();
