// 130. Surrounded Regions
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, char x) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(board[i][j]=='O') {
            board[i][j] = x;
            dfs(board, i+1, j, x);
            dfs(board, i-1, j, x);
            dfs(board, i, j+1, x);
            dfs(board, i, j-1, x);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        for(int i=0;i<board.size();i++) {
            if(board[i][0]=='O') {
                dfs(board, i, 0, '-');
            }
            if(board[i][board[i].size()-1]=='O') {
                dfs(board, i, board[i].size()-1, '-');
            }
        }
        for(int i=0;i<board[0].size();i++) {
            if(board[0][i]=='O') {
                dfs(board, 0, i, '-');
            }
            if(board[board.size()-1][i]=='O') {
                dfs(board, board.size()-1, i, '-');
            }
        }
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]=='O') {
                    dfs(board, i, j, 'X');
                }
            }
        }
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j]=='-') {
                    board[i][j]='O';
                }
            }
        }
    }
};
