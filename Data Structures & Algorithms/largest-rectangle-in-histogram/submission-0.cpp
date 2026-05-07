class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i,j,n=heights.size(),ans=INT_MIN,area=INT_MIN;
        stack<pair<int,int>> stk;
        pair<int,int> temp;
        for(i=0;i<n;i++)
        {
            if(stk.empty())
                stk.push({i,heights[i]});
            else
            {
                if(heights[i]>=stk.top().second)
                    stk.push({i,heights[i]});
                else
                {
                    while(stk.size()>0 && heights[i]<stk.top().second)
                    {
                        ans= max(stk.top().second*(i-stk.top().first),ans);
                        temp={stk.top().first,heights[i]};
                        stk.pop();
                    }
                    stk.push(temp);
                }
            }
        }
        while(!stk.empty())
        {
            area=(stk.top().second)*(n-stk.top().first);
            ans= max(area,ans);
            stk.pop();
        }
        return ans;
    }
};
