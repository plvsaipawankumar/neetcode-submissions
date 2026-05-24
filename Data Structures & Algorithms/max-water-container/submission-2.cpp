class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i,n =heights.size(),ans=0,l=0,r=heights.size()-1;
        pair<int,int> maximum_height={0,0};
        while(l<r)
        {
            ans = max(ans,min(heights[l],heights[r])*(r-l));
            if(heights[l]<heights[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
