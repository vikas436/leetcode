// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt=0,pre=nums[0],j=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==pre) {
                cnt++;
            } else {
                nums[j]=nums[i];
                j++;
                pre = nums[i];
            }
        }
        return nums.size()-cnt;
    }
};
