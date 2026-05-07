class Solution {
public:
    int trap(vector<int>& height) {
        int max_value=INT_MIN,i,j,extrawater=0,n=height.size(),ans=0,partial_ans=0,prevmax=height[0];
        map<int,vector<int>> m;
        for(i=0;i<n;i++)
        {
            max_value=max(max_value,height[i]);
            m[height[i]].push_back(i);
        }
        for(i=1;i<n;i++)
        {
            if(prevmax<=height[i])
            {
                prevmax=height[i];
                ans+=partial_ans;
                partial_ans=0;
            }
            else
            {
                partial_ans+=(prevmax-height[i]);
            }
        }
        prevmax=height[n-1],partial_ans=0;
        for(i=n-2;i>=0;i--)
        {
            if(prevmax<=height[i])
            {
                prevmax=height[i];
                ans+=partial_ans;
                partial_ans=0;
            }
            else
            {
                partial_ans+=(prevmax-height[i]);
            }
        }
        int mh=m[max_value].size();
        if(mh>1)
        {
            extrawater=0;
            for(i=1;i<mh;i++)
            {
                for(j=m[max_value][i-1]+1 ;j<m[max_value][i];j++)
                {
                    extrawater+=(max_value-height[j]);
                }
            }
        }
        return ans-extrawater;
    }
};
