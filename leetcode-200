// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void dfs(vector<vector<char>>& vec, int i, int j) {
        if(i<0 || j<0 || i>=vec.size() || j>=vec[i].size() || vec[i][j]=='0') return;
        vec[i][j]='0';
        dfs(vec, i+1, j);
        dfs(vec, i-1, j);
        dfs(vec, i, j+1);
        dfs(vec, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};    
