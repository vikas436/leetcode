// https://leetcode.com/problems/minimum-falling-path-sum-ii/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if(arr.empty()) return 0;
        if(arr.size()==1) return arr[0][0];
        vector<vector<int> > vec( arr.size() , vector<int> (arr.size(), 0));
        int res = INT_MAX;
        for(int i=0;i<arr.size();i++) {
            pair<int,int>p1;
            pair<int,int>p2;
            if(i>0){
                if(vec[i-1][0]<vec[i-1][1]) {
                    p1 = make_pair(vec[i-1][0], 0);
                    p2 = make_pair(vec[i-1][1], 1);
                } else {
                    p1 = make_pair(vec[i-1][1], 1);
                    p2 = make_pair(vec[i-1][0], 0);
                }
                for(int k=2;k<vec.size();k++) {
                    if(p1.first>vec[i-1][k]) {
                        p2 = p1;
                        p1 = make_pair(vec[i-1][k], k);
                    } else if(p2.first>vec[i-1][k]) {
                        p2 = make_pair(vec[i-1][k], k);
                    }
                }
            }
            
            for(int j=0;j<arr.size();j++) {
                if(i==0) {
                    vec[i][j]=arr[i][j];
                } else {
                    int num;
                    if(p1.second==j) {
                        num = p2.first;
                    } else {
                        num = p1.first;
                    }
                    vec[i][j] = arr[i][j]+num;
                    num = vec[i][j];
                    if(i==arr.size()-1) {
                        if(res>num) res = num;
                    }
                }
            }
        }
        return res;
    }
};
