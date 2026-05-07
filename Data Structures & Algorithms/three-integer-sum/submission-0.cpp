class Solution {
public:

    bool condition(int i,int j,int c)
    {
        return ((c-1) != i )&&( (c-1)!=j) && (c>0);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int i,j,a,b,c,n=nums.size();
        map<int,int> m;
        map<vector<int>,int> mvi;
        for(i=0;i<n;i++)
            m[nums[i]]=i+1;
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                c=m[-nums[i]-nums[j]];
                if(condition(i,j,c))
                {
                    a=nums[i],b=nums[j],c=nums[--c];
                    vector<int> v{a,b,c};
                    sort(v.begin(),v.end());
                    if(mvi[v]==0)
                    {
                        ans.push_back(v);
                        mvi[v]++;
                    }                    
                }
            }
        }
        return ans;
    }
};
