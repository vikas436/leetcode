// 36. Valid Sudoku

class Solution {
public:
    bool row(vector<vector<char>>& board, int row) {
        set<char>st;
        for(int i=0;i<board.size();i++) {
            if(board[row][i]=='.') continue;
            if(st.find(board[row][i])!=st.end()) return true;
            st.insert(board[row][i]);
        }
        return false;
    }
    bool col(vector<vector<char>>& board, int col) {
        set<char>st;
        for(int i=0;i<board.size();i++) {
            if(board[i][col]=='.') continue;
            if(st.find(board[i][col])!=st.end()) return true;
            st.insert(board[i][col]);
        }
        return false;
    }
    bool box(vector<vector<char>>& board, int row, int col) {
        set<char>st;
        for(int i=row;i<row+3;i++) {
            for(int j=col;j<col+3;j++) {
                if(board[i][j]=='.') continue;
               if(st.find(board[i][j])!=st.end()) return true; 
                st.insert(board[i][j]);
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(row(board, i)) return false;
                if(col(board, i)) return false;
                if(i%3==0 && j%3==0 && box(board,i,j)) return false;
            }
        }
        return true;
    }
};
