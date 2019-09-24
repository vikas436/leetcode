// 63. Unique Paths II

class Solution {
public:
    int init(vector<vector<int>>& obstacleGrid,vector<vector<long>>& vec, int m, int n) {
        if(obstacleGrid[0][0]==1) return 0;
        bool row=true,col=true;
        int i=0;
        for(;i<m;i++) {
            vec[i][0]=1;
            if(obstacleGrid[i][0]==1) {row=false;break;}
        }
        int j=0;
        for(;j<n;j++) {
            vec[0][j]=1;
            if(obstacleGrid[0][j]==1) {col=false;break;}
        }
        if(row==false)
        for(;i<m;i++) {
            vec[i][0]=0;
        }
        if(col==false) 
        for(;j<n;j++) {
            vec[0][j]=0;
        }
        return -1;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0) return 0;
        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0]==0) return 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>>vec(m,vector<long>(n,0));
        int res = init(obstacleGrid, vec, m, n);
        if(res!=-1) return res;
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(obstacleGrid[i][j]==1) continue;
                vec[i][j] = vec[i-1][j]+vec[i][j-1];
            }
        }
        return vec[m-1][n-1];
    }
};
