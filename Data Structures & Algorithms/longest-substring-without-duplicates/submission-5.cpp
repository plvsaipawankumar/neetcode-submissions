class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,ans=0,subans=0,n=s.size(),l=0;
        map<char,int> lastOccurance;
        
        for(i=0;i<n;i++)
        {
            if(lastOccurance[s[i]])
            {
                l=max(lastOccurance[s[i]],l);
                lastOccurance[s[i]]=i+1;
            }
            else
            {
                lastOccurance[s[i]]=i+1;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
