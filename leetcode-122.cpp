// 122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int res=0,min=prices[0];
        for(int i=1;i<prices.size();i++) {
            if(min>=prices[i]) {
                min = prices[i];
            } else {
                res += prices[i]-min;
                min = prices[i];
            }
        }
        return res;
    }
};
