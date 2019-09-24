// 64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();    
    vector<vector<long>>vec(m,vector<long>(n,0));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(i==0 && j==0){
                vec[i][j] = grid[i][j];
                continue;
            }
            if(i==0) {
                vec[i][j]=grid[i][j]+vec[i][j-1];
            } else if(j==0) {
                vec[i][j]=grid[i][j]+vec[i-1][j];
            } else 
            vec[i][j] = min(vec[i-1][j],vec[i][j-1])+grid[i][j];
        }
    }    
    return vec[m-1][n-1];    
    }
};
