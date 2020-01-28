//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        vector<int>vec(prices.size(), 0);
        int mn=INT_MAX, res1=INT_MIN, res2=INT_MIN, mx=INT_MIN;
        for(int i=0;i<prices.size();i++) {
            if(mn>prices[i]) mn = prices[i];
            res1 = max(res1, prices[i]-mn);
            vec[i] = res1;
        }
        for(int i=prices.size()-1;i>0;i--) {
            if(mx<prices[i]) mx = prices[i];
            res2 = max(res2, mx-prices[i]+vec[i-1]);
        }
        return max(res1, res2);
    }
};
