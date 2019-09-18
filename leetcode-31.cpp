// 31. Next Permutation
/*
1. find from last arr[i]>arr[i-1]
2. sort if i==0
3. else replace arr[i-1] with arr[next greather number index with arr[i-1]]
4. sort from i to end.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        for(;i>0;i--) {
            if(nums[i]>nums[i-1]) {
                break;
            }
        }
        if(i==0) {
            sort(nums.begin(),nums.end());
        } else {
            int num = nums[i-1],max=-1;
            for(int j=i;j<nums.size();j++) {
                if(num<nums[j]) {
                    if(max==-1) {
                        max=j;
                    } else {
                        if(nums[max]>nums[j]) {
                            max=j;
                        }
                    }
                }
            }
            swap(nums[max],nums[i-1]);
            sort(nums.begin()+i,nums.end());
        }
    }
};
