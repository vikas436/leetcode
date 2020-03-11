// https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>vec;
        if(nums.size()==0) return vec;
        vec.resize(nums.size(), 1);
        sort(nums.begin(), nums.end());
        int ind = 0, val=0;
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0) {
                    vec[i] = max(vec[i], vec[j]+1);
                    if(vec[i]>val) {
                        ind = i;
                        val = vec[i];
                    }
                }
            }
        }
        vector<int>res;
        res.push_back(nums[ind]);
        while(ind>0) {
            int flg = 0;
            for(int i=ind-1;i>=0;i--) {
                if(vec[i]==vec[ind]-1 && nums[ind]%nums[i]==0) {
                    res.push_back(nums[i]);
                    ind = i;
                    flg = 1;
                    break;
                }
            }
            if(flg==0) break;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
