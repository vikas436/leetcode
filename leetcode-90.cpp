//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    set<vector<int>> st;
    void subset(vector<int>&vec, int s,int cnt, int k, int n, vector<int>&res) {
        if(cnt>=k) {
            st.insert(res);
            return;
        } else {
            for(int i=s;i<n;i++) {
                res.push_back(vec[i]);
                subset(vec, i+1,cnt+1, k, n, res);
                res.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>vec;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            subset(nums,0,0,i, nums.size(),vec);
            vec.clear();
        }
        st.insert(nums);
        for(auto it=st.begin();it!=st.end();it++) {
            res.push_back(*it);
        }
        st.clear();
        return res;
    }
};
