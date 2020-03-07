// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0 && amount!=0) return -1;
        if(coins.size()==0) return 1;
        vector<vector<int>> vec(coins.size()+1, vector<int>(amount+1, INT_MAX));
        for(int i=0;i<=coins.size();i++) {
            vec[i][0] = 0;
        }
        for(int i=1;i<=coins.size();i++) {
            for(int j=1;j<=amount;j++) {
                if(j-coins[i-1]>=0 && vec[i][j-coins[i-1]]!=INT_MAX) {
                    vec[i][j] = min(vec[i-1][j], 1 + vec[i][j-coins[i-1]]);
                } else vec[i][j] = vec[i-1][j];
            }
        }
        if(vec[coins.size()][amount]==INT_MAX) return -1;
        return vec[coins.size()][amount];
    }
};
