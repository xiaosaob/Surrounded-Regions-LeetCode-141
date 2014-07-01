// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        if(!n) return;
        
        for(int i = 0; i < n; ++i) {
            if(board[0][i] == 'O')
                board[0][i] = 'o';
            if(board[m-1][i] == 'O')
                board[m-1][i] = 'o';
        }
        
        for(int j = 0; j < m; ++j) {
            if(board[j][0] == 'O')
                board[j][0] = 'o';
            if(board[j][n-1] == 'O')
                board[j][n-1] = 'o';
        }
        
        for(int i = 0; i < n; ++i) {
            if(board[0][i] == 'o')
                helper(board, 0, i);
            if(board[m-1][i] == 'o')
                helper(board, m-1, i);
        }
        
        for(int j = 0; j < m; ++j) {
            if(board[j][0] == 'o')
                helper(board, j, 0);
            if(board[j][n-1] == 'o')
                helper(board, j, n-1);
        }
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'o') {
                    board[i][j] = 'O';
                }
    }
    
    void helper(vector<vector<char> > &board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        board[row][col] = 'o';
        if(row-1 >= 0 && board[row-1][col] == 'O')
            helper(board, row-1, col);
        if(row+1 < m && board[row+1][col] == 'O')
            helper(board, row+1, col);
        if(col-1 >= 0 && board[row][col-1] == 'O')
            helper(board, row, col-1);
        if(col+1 < n && board[row][col+1] == 'O')
            helper(board, row, col+1);
    }
};
