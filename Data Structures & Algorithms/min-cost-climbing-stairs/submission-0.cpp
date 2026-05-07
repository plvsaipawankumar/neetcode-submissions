class Solution {
public:
    vector<int> minstaircost;
    int dfs(vector<int>& cost,int n,int i)
    {
        if(i>=n)return 0;
        if(minstaircost[i]!=INT_MAX) return minstaircost[i];

        return minstaircost[i]=min(dfs(cost,n,i+1),dfs(cost,n,i+2))+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        minstaircost.resize(n,INT_MAX);
        return min(dfs(cost,n,0),dfs(cost,n,1));
    }
};
