class Solution {
public:
    void rotate(vector<int> &ans,int n)
    {
        int i,temp;
        for(i=0;i<n/2;i++)
        {
            temp=ans[i];
            ans[i]=ans[n-1-i];
            ans[n-1-i] = temp;
        }
        return ;
    }
    void fill (vector<int> &track,int len,int assign)
    {
        for(int i=0;i<len;i++)
        {
            track[i]=assign;
        }
        return ;
    }
    vector<int> dailyTemperatures(vector<int>& temp) {
        int i,n=temp.size();
        vector<int> track(101,0),ans;
        for(i=n-1;i>=0;i--)
        {
            if(track[temp[i]]==0)
                ans.push_back(0);
            else
            {
                ans.push_back(track[temp[i]]-i);
            }
            fill(track,temp[i],i);
        }
        rotate(ans,n);
        return ans;
    }
};
