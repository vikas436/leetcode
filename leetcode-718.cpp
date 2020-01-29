// https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res=0;
        if(A.size()==0 || B.size()==0) return res;
        vector<vector<int>> vec(A.size()+1, vector<int>(B.size()+1,0));
        for(int i=1;i<=A.size();i++) {
            for(int j=1;j<=B.size();j++) {
                if(A[i-1]==B[j-1]) {
                    vec[i][j] = vec[i-1][j-1] + 1;
                } 
                if(vec[i][j]>res) res = vec[i][j];
            }
        }
        return res;
    }
};
