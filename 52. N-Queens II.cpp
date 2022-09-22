/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 9
*/ 

#include<bits/stdc++.h>
using namespace std;

int board[11][11];
class Solution {
public:
    
    bool isPossible(int n, int row, int col)
    {
        for (int i = row - 1; i >= 0; i--)
            if (board[i][col] == 1)
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 1)
                return false;
        return true;
    }
    int count = 0;
    int nQueenHelper(int n, int row)
    {

        if (row == n)
        {
            count++;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (isPossible(n, row, j))
                {
                    board[row][j] = 1;
                    nQueenHelper(n, row + 1);
                    board[row][j] = 0;
                }
            }
        }
        return count;
    }

    int placeNQueens(int n)
    {
        memset(board, 0, 11 * 11 * sizeof(int));
        return nQueenHelper(n, 0);
    }

    int totalNQueens(int n) {
        return placeNQueens(n);
    }
};
