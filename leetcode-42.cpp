// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int res=0;
        vector<int>left(height.size()),right(height.size());
        left[0]=height[0];
        right[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++) {
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;i--) {
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<height.size();i++) {
            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};
