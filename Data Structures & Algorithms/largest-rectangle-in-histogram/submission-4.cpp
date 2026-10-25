class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int start,i,n=heights.size();
        stack<pair<int,int>> pillar;
        int ans=0;
        for(i=0;i<n;i++)
        {
            start=i;
            while(!pillar.empty() && pillar.top().first>heights[i])
            {
                ans=max(ans,pillar.top().first*(i-pillar.top().second));
                start=pillar.top().second;
                pillar.pop();
            }
            pillar.push({heights[i],start});
        }
        while(!pillar.empty())
        {
            pair<int,int> top = pillar.top();pillar.pop();
            ans=max(ans,top.first*(n-top.second));
        }
        return ans;
    }
};
