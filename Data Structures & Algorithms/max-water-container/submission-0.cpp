class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i,j,ans=0,n=heights.size();
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
                ans= max(ans,min(heights[i],heights[j])*(j-i));
        }
        return ans;
    }
};
