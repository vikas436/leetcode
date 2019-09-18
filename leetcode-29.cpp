// 29. Divide Two Integers
// TIMEOUT need to uer math&bit manipulation...

class Solution {
public:
    int divide(int x, int y) {
        long long dividend=x, divisor=y;
        long long sign=1;
        if(dividend<0 && divisor<0) {
            dividend=dividend*-1;
            divisor=divisor*-1;
        } else if(dividend<0 || divisor<0) {
            if(divisor<0) {
                divisor=divisor*-1;
            } else {
                dividend=dividend*-1;
            }
            sign=-1;
        }
        int num=0;
        if(dividend<divisor) return 0;
        long long div=divisor,cnt=0;
        while(dividend>=divisor) {
            dividend = dividend-div;
            cnt++;
        }
        int num1=cnt*sign;
        if(num1==INT_MIN) {
            return num1*-1-1;
        }
        return num1;
    }
};
