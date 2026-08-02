class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,minimum=prices[0];
        int i,n=prices.size();
        for(i=1;i<n;i++){
            if(prices[i]<minimum)
                minimum=prices[i];
            else{
                ans = max(ans,prices[i]-minimum);
            }
        }
        return ans;
    }
};
