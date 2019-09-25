//70. Climbing Stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int a=1,b=1,c,num=1;
        while(num<n) {
            c = a+b;
            a = b;
            b = c;
            num++;
        }
        return b;
    }
};

