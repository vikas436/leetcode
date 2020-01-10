// https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution {
public:
    static bool comp(pair<int ,int>pr1, pair<int ,int>pr2) {
        return pr1.second<pr2.second;
    }  
    
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()<=0) return 0;
        pair<int, int> pr;
        vector<pair<int, int>>vec;
        for(int i=0;i<pairs.size();i++) {
            pr = make_pair(pairs[i][0], pairs[i][1]);
            vec.push_back(pr);
        }
        sort(vec.begin(), vec.end(),comp);
        int cnt=1;
        int i=0,j=1;
        while(i<j && j<pairs.size()) {
            if(vec[i].second<vec[j].first){
                cnt++;
                i=j;
                j++;
            } else {
                j++;
            }
        }
        return cnt;
    }
};
