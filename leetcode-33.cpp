// 33. Search in Rotated Sorted Array

class Solution {
public:
    int binarySearch(vector<int>&vec, int l, int r,int d) {
        if(l>r) return -1;
        int m = (l+r)/2;
        if(vec[m]==d) return m;
        if(d>vec[m]) return binarySearch(vec,m+1,r,d);
        else return binarySearch(vec,l,m-1,d);
    }
    int rotate(vector<int>&vec, int l, int r) {
        if(l>r) return -1;
        int m = (l+r)/2;
        if(m+1<vec.size() && vec[m]>vec[m+1]) 
            return m+1;
        if(m-1>0 && vec[m-1]>vec[m])
            return m;
        if(vec[0]<vec[m]) return rotate(vec,m+1,r);
        else return rotate(vec,l, m-1);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums[0]<=nums[nums.size()-1]) {
            return binarySearch(nums, 0, nums.size()-1, target);
        }
        int ind = rotate(nums, 0, nums.size()-1);
        if(ind==-1) return ind;
        if(nums[ind]<=target && nums[nums.size()-1]>=target) {
            return binarySearch(nums, ind, nums.size()-1, target);
        } else {
            return binarySearch(nums, 0, ind-1, target);
        }
    }
};
