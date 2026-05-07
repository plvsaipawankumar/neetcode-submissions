class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j,n=prices.size(),buy_price=prices[0],profit=0;
        for(i=1;i<n;i++)
        {
            if(buy_price>=prices[i])
                buy_price=prices[i];
            else
            {
                profit=max(profit,(prices[i]-buy_price));
            }
        }
        return profit;
    }
};
