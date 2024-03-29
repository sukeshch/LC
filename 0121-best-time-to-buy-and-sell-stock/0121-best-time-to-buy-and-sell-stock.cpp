class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_seen = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - min_seen);
            
            min_seen = min(min_seen, prices[i]);
        }
        return max_profit;
    }
};