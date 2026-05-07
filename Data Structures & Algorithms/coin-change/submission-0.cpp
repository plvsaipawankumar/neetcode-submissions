class Solution {
public:
    vector<int> cache;
    int mincoins(vector<int>& coins, int amount,int pos)
    {
        if(amount<0 || pos<0)
            return 1e9;
        if(amount == 0)
            return 0;
        if(cache[amount]!=0)
            return cache[amount];
        int take=mincoins(coins,amount-coins[pos],pos)+1;
        int non_take = mincoins(coins,amount,pos-1);
        return cache[amount]=min(take,non_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        cache.resize(amount+1,0);
        int ans=mincoins(coins,amount,coins.size()-1);
        return (ans>=1e9)?-1:ans;
    }
};
