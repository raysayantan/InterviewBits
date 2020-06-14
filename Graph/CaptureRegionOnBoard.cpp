/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input Format:

    First and only argument is a N x M character matrix A
Output Format:

    make changes to the the input only as matrix is passed by reference.
Constraints:

    1 <= N,M <= 1000
For Example:

Input 1:
    A = [ [X, X, X, X],
          [X, O, O, X],
          [X, X, O, X],
          [X, O, X, X] ]
Output 1:
    After running your function, the board should be:
    A = [ [X, X, X, X],
          [X, X, X, X],
          [X, X, X, X],
          [X, O, X, X] ]
Explanation:
    O in (4,2) is not surrounded by X from below.
*/
void markCell(vector<vector<char>>& board, pair<int, int> cell, int row, int col){
        //One cell have four neighbouring cells top, left, bottom and right
        //need to check its contents and if this is 'O' then we can move on that
        //and we will do BFS and mark this cell with I
        int i = cell.first;
        int k = cell.second;
        //top
        if(i-1 >= 0 && board[i-1][k] == 'O'){
            board[i-1][k] = 'I';
            markCell(board, make_pair(i-1,k),row,col);
        }
        //left
        if(k-1 >= 0 && board[i][k-1] == 'O'){
            board[i][k-1] = 'I';
            markCell(board, make_pair(i, k-1), row, col);
        }
        //bottom
        if(i+1 < row && board[i+1][k] == 'O'){
            board[i+1][k] = 'I';
            markCell(board, make_pair(i+1,k), row, col);
        }
        //right
        if(k+1 < col && board[i][k+1] == 'O'){
            board[i][k+1] = 'I';
            markCell(board,make_pair(i, k+1), row, col);
        }
    }
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows = A.size();
        if(rows <= 2) return;
        int cols = A[0].size();
        if(cols <= 2) return;
        //check 'O' in first row and mark all connected 'O'
        for(int i = 0; i < cols; i++){
            if(A[0][i] == 'O'){
                A[0][i] = 'I';
               if(i-1 >= 0 && A[0][i-1] == 'O'){
                   A[0][i-1] = 'I';
                   markCell(A, make_pair(0, i-1), rows, cols);
               }
                
               if(i+1 < cols && A[0][i+1] == 'O'){
                   A[0][i+1] = 'I';
                   markCell(A, make_pair(0, i+1), rows, cols);
               }
                
               if(A[1][i] == 'O'){
                   A[1][i] = 'I';
                   markCell(A, make_pair(1, i), rows, cols);
               }
            }
        }
        
        //check 'O' in first col and mark all connected 'O'
        for(int i = 0; i < rows; i++){
           if(A[i][0] == 'O'){
               A[i][0] = 'I';
               if(i-1 >= 0 && A[i-1][0] == 'O'){
                   A[i-1][0] = 'I';
                   markCell(A, make_pair(i-1, 0), rows, cols);
               }
                
               if(i+1 < rows && A[i+1][0] == 'O'){
                   A[i+1][0] = 'I';
                   markCell(A, make_pair(i+1, 0), rows, cols);
               }
                
               if(A[i][1] == 'O'){
                   A[i][1] = 'I';
                   markCell(A, make_pair(i, 1), rows, cols);
               }
            } 
        }
        
        //check 'O' in last row and mark all connected 'O'
        for(int i = 0; i < cols; i++){
            if(A[rows-1][i] == 'O'){
                A[rows-1][i] = 'I';
               if(i-1 >= 0 && A[rows-1][i-1] == 'O'){
                   A[rows-1][i-1] = 'I';
                   markCell(A, make_pair(rows-1, i-1), rows, cols);
               }
                
               if(i+1 < cols && A[rows-1][i+1] == 'O'){
                   A[rows-1][i+1] = 'I';
                   markCell(A, make_pair(rows-1, i+1), rows, cols);
               }
                
               if(A[rows-2][i] == 'O'){
                   A[rows-2][i] = 'I';
                   markCell(A, make_pair(rows-2, i), rows, cols);
               }
            }
        }
        
        //check 'O' in last col and mark all connected 'O'
        for(int i = 0; i < rows; i++){
            if(A[i][cols-1] == 'O'){
                A[i][cols-1] = 'I';
               if(i-1 >= 0 && A[i-1][cols-1] == 'O'){
                   A[i-1][cols-1] = 'I';
                   markCell(A, make_pair(i-1, cols-1), rows, cols);
               }
                
               if(i+1 < rows && A[i+1][cols-1] == 'O'){
                   A[i+1][cols-1] = 'I';
                   markCell(A, make_pair(i+1, cols-1), rows, cols);
               }
                
               if(A[i][cols-2] == 'O'){
                   A[i][cols-2] = 'I';
                   markCell(A, make_pair(i, cols-2), rows, cols);
               }
            }
        }
        
        //Now traverse through the matrix and make all the 'I' with 'O', as this
        //are connected with a cell having 'O' at the edge and can not be marked 'X'
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < cols; k++){
                if(A[i][k] == 'I'){
                    A[i][k] = 'O';
                } else if(A[i][k] == 'O'){
                    A[i][k] = 'X';
                }
            }
        }
}
