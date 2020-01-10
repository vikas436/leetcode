// 121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, res = 0;
        for(int i=0;i<prices.size();i++) {
            if(min > prices[i]) {
                min = prices[i];
            }
            res = max(res, prices[i]-min);
        }
        return res;
    }
};
