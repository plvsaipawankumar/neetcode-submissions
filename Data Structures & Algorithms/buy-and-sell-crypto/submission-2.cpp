class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,n=prices.size(),ans=0,min_price=prices[0];
        for(i=0;i<n;i++){
            if(prices[i]<min_price){
                min_price=prices[i];
            }
            else{
                ans=max(ans,prices[i]-min_price);
            }
        }
        return ans;
    }
};
