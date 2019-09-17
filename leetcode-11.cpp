// 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area = 0,val;
        while(i<j) {
            val = min(height[i],height[j])*(j-i);
            if(val>area) area = val;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return area;
    }
};
 
