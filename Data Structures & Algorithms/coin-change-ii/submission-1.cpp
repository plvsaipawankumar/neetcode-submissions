class Solution {
public:
    set<vector<int>> ans;
    int ways(int amount, vector<int>& coins,int pos,vector<vector<int>> & cache)
    {
        if(amount<0 || pos<0)
            return 0;
        if(amount==0)
            return 1;
        if(cache[amount][pos]!=0)return cache[amount][pos];
        return cache[amount][pos]=ways(amount-coins[pos],coins,pos,cache)+ways(amount,coins,pos-1,cache);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> cache(amount+1,vector<int>(n+1,0));

        sort(coins.begin(),coins.end());
        return ways(amount,coins,n-1,cache);
    }
};
